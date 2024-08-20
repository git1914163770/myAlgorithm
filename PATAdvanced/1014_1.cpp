#include<bits/stdc++.h>
using namespace std;
//https://blog.csdn.net/a131529/article/details/133763088
int N, M, K, Q;

// 顾客结构体，包含处理时间和服务结束时间
struct member {
    int process_time; // 处理时间
    int level_time = 0; // 服务结束时间，初始为0（表示尚未开始服务）
} c[1001]; // 最多支持1000个顾客

int main() {
    // 输入N、M、K、Q
    cin >> N >> M >> K >> Q;

    int cursor = 1; // 当前排队的顾客标号，初始化为1

    // 创建N个队列，分别代表N个窗口
    queue<int> q[N];

    // 输入每个顾客的处理时间
    for (int i = 1; i <= K; i++)
        cin >> c[i].process_time;

    // 模拟从480分钟到1020分钟的每一分钟
    for (int t = 480; t < 1020; t++) {
        // 送客（处理离开的顾客）
        for (int j = 0; j < N; j++) {
            // 如果窗口j有顾客
            if (q[j].size()) {
                int k = q[j].front(); // 获取当前在窗口j前面的顾客
                // 如果顾客的服务结束时间正好是当前时间t，则该顾客离开窗口
                if (c[k].level_time == t)
                    q[j].pop();
            }
        }

        // 入队（新顾客到达并排队）
        for (int j = 0; j < N; j++) { // 遍历所有窗口
            // 如果窗口j的队列长度小于i且还有顾客可以排队
            if (q[j].size() < M && cursor <= K) {
                q[j].push(cursor); // 顾客cursor排队到窗口j
                cursor++; // 更新下一个顾客的标号
            }
        }
        

        // 接客（更新顾客的服务结束时间）
        for (int j = 0; j < N; j++) {
            // 如果窗口j有顾客
            if (q[j].size()) {
                int k = q[j].front(); // 获取当前在窗口j前面的顾客
                // 如果该顾客的服务结束时间还未设置
                if (c[k].level_time == 0)
                    c[k].level_time = c[k].process_time + t; // 计算并设置顾客的服务结束时间
            }
        }
    }

    // 处理Q个查询
    while (Q--) {
        int p; 
        cin >> p; // 输入顾客标号p
        // 如果顾客p的服务结束时间为0，则输出“Sorry”
        // 5点前的服务的（即使结束时间超过5点）已经都设置了
        if (c[p].level_time == 0)
            cout << "Sorry" << endl;
        else
            // 否则，输出顾客p的服务结束时间，格式为“HH:MM”
            cout << setw(2) << setfill('0') << c[p].level_time / 60 << ":" << setw(2) << setfill('0') << c[p].level_time % 60 << endl;
    }
}
