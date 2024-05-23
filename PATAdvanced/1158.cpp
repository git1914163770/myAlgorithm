// 超过k次短电话（不超过5分钟）给不同的人，但是不超过20%人回电
// 两个嫌疑者互相打电话
// https://blog.csdn.net/liuchuo/article/details/126222735
#include <iostream>
#include <vector>
using namespace std;
int k, n, m, c, r, d, p[1001], sc[1001], rec[1001], mark[1001], record[1001][1001];
vector<int> su;
int Find(int a) {
    if (p[a] != a) return p[a] = Find(p[a]);
    return a;
}
void add(int a, int b) {
    int f1 = Find(a), f2 = Find(b);
    // 小的作为根
    if (f1 < f2) p[f2] = f1;
    else p[f1] = f2;
}
int main() {
    for (int i = 1; i <= 1000; i++) p[i] = i;
    cin >> k >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c >> r >> d;
        record[c][r] += d;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (record[i][j] && record[i][j] <= 5) {
                sc[i]++;
                if (record[j][i]) rec[i]++;
            }
        }
        if (sc[i] > k && rec[i] * 5 <= sc[i]) su.push_back(i);
    }
    if (su.empty()) {
        cout << "None";
        return 0;
    }
    for (int i = 0; i < su.size(); i++) {
        for (int j = i + 1; j < su.size(); j++) {
            if (record[su[i]][su[j]] && record[su[j]][su[i]]) add(su[i], su[j]);
        }
    }
    for (int i = 0; i < su.size(); i++) {
        if (mark[su[i]]) continue;
        cout << su[i];
        for (int j = i + 1; j < su.size(); j++) {
            if (Find(su[i]) == Find(su[j])) {
                cout << ' ' << su[j];
                mark[su[j]] = 1;
            }
        }
        cout << '\n';
    }
    // 测试代码 A B 一起 B C一起 AC是否一起？
    // for(int i = 0;i < su.size();i++){
    //     for(int j = i +1;j < su.size();j++){
    //         if(Find(su[i]) == Find(su[j])){
    //             if (!record[su[i]][su[j]] || !record[su[j]][su[i]]) cout << "test No";
    //         }
    //     }
    // }
    return 0;
}