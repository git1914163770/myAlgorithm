#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, K, num, used[101], ans[101];
vector<int> pro;
vector<int> rea;
vector<vector<int>> equa[101];
string s;
// https://liuchuo.blog.csdn.net/article/details/137613818
// https://blog.csdn.net/qq_52661062/article/details/114701346
bool cmp(const vector<int> &a, const vector<int> &b) {
    return a < b;
}
void dfs(int x) {
    if (x == M) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < equa[pro[i]][ans[i]].size(); j++) {
                if (j != 0) cout << " + ";
                printf("%02d",equa[pro[i]][ans[i]][j]);
            }
            printf(" -> %02d\n",pro[i]);
        }
        // return;
        exit(0); // 只输出一组
    }
    for (int i = 0; i < equa[pro[x]].size(); i++) {
        int flag = 1;
        vector<int> A = equa[pro[x]][i];
        for (auto it : A) 
            // 题目要求方程式中的每个反应物只能使用1次
            // 可以考虑用set/map
            if (used[it] != 1) {
                flag = 0;
                break;
            }
        if (flag == 0) continue;
        for (auto it : A) used[it] = 2;
        ans[x] = i;
        dfs(x + 1);
        for (auto it : A) used[it] = 1;
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        used[num] = 1;
        rea.push_back(num);
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> num;
        if(used[num] == 1) equa[num].push_back({num});
        pro.push_back(num);
    }
    cin >> K;
    vector<int> temp;
    for (int i = 0; i < K; i++) {
        temp.clear();
        while (cin >> num >> s) {
            temp.push_back(num);
            if (s == "->") {
                cin >> num;
                equa[num].push_back(temp);
                break;
            }
        }
    }
    for (int i = 0; i < M; i++) sort(equa[pro[i]].begin(), equa[pro[i]].end(), cmp);
    dfs(0);
    return 0;
}