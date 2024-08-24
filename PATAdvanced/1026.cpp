#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

//https://blog.csdn.net/liuchuo/article/details/54576965
int n, m, k, H, M, S, t, table, vtable, cnt, now, nowt;
// T V 某个时刻到达的客户玩耍的时间,某个时刻到达的客户是否是VIP
// 21*60*60=75600
// 也可以不用T V，先对最开始的输入排序，同时新增正在处理的下标 
int T[100000], V[100000];
// 分别记录客户的到达时刻和开始玩耍时刻,vip数组中存储某张桌子是不是vip专属
int AnsI[10001], AnsO[10001], vip[101];
int Table[101], num[101]; // 记录每张桌子的剩余使用时间及服务数量
queue<int> Wait, vWait; // 普通客户队列和VIP客户队列

int main() {
    // 读取客户数量
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        // 读取客户到达时间
        scanf("%d:%d:%d", &H, &M, &S);
        t = H * 3600 + M * 60 + S; // 将时间转换为秒
        // 读取客户所需玩耍时间和VIP标志
        scanf("%d %d", &T[t], &V[t]);
        // 限制最大玩耍时间为120分钟，即7200秒
        T[t] = min(T[t], 120) * 60;
    }
    
    // 读取桌子数量和VIP桌子数量
    // 桌子编号从1开始
    scanf("%d %d", &m, &k);
    for (int i = 0; i < k; i++) {
        // 读取VIP桌子的编号
        scanf("%d", &t);
        vip[t] = 1; // 标记为VIP桌子
    }
    
    // 遍历从08:00:00到21:00:00的每秒钟
    for (int Time = 28800; Time < 75600; Time++, table = vtable = now = 0) {
        // 处理到达的客户
        if (T[Time] && V[Time]) vWait.push(Time); // VIP客户
        else if (T[Time]) Wait.push(Time); // 普通客户
        
        // 更新桌子的状态
        for (int i = 1; i <= m; i++) {
            if (Table[i] > 0) Table[i]--; // 递减桌子上客户的剩余使用时间
            if (Table[i] == 0 && vip[i] && vtable == 0) vtable = i; // 记录空闲的VIP桌子
            if (Table[i] == 0 && table == 0) table = i; // 记录空闲的普通桌子
        }
        
        // 分配桌子给客户
        if (!vWait.empty() && (table || vtable)) {
            now = vWait.front(); // VIP客户到达时间
            nowt = vtable; // 使用VIP桌子
            if (vtable != 0) vWait.pop(); // 使用VIP桌子
            else {
                nowt = table; // 使用普通桌子
                if (!Wait.empty() && Wait.front() < vWait.front()) {
                    now = Wait.front(); // 处理普通客户
                    Wait.pop();
                } else vWait.pop(); // 否则VIP客户排队继续
            }
        } else if (!Wait.empty() && (table || vtable)) {
            if (table != 0) nowt = table; // 如果普通桌子空闲，分配给普通客户
            else nowt = vtable; // 否则分配VIP桌子
            now = Wait.front(); // 普通客户到达时间
            Wait.pop();
        }
        
        if (now == 0) continue; // 如果没有客户等待，继续下一个时间点
        // 更新桌子的状态
        // nowt记录当前使用的桌子编号
        Table[nowt] = T[now];
        // 记录客户的到达时间和开始玩耍时间
        AnsI[cnt] = now;
        AnsO[cnt] = Time;
        cnt++;
        num[nowt]++; // 更新桌子使用次数
    }
    
    for (int i = 0; i < cnt; i++)
        printf("%02d:%02d:%02d %02d:%02d:%02d %d\n",
               AnsI[i] / 3600, AnsI[i] % 3600 / 60, AnsI[i] % 60,
               AnsO[i] / 3600, AnsO[i] % 3600 / 60, AnsO[i] % 60,
               (AnsO[i] - AnsI[i] + 30) / 60); // 客户使用时间（四舍五入到分钟）

    // 输出每张桌子的使用情况
    for (int i = 1; i <= m; i++) {
        if (i != 1) printf(" ");
        printf("%d", num[i]);
    }
    return 0;
}
