#include <iostream>
#include <vector>
using namespace std;
struct node {
    int data, next;
}A[100001];
vector<int> L, ans, E[100001];
// 乙1110
int s, n , a, t, k, mark, cnt, c;
int main() {
    cin >> s >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> A[a].data >> A[a].next;
    }
    t = s;
    while (t != -1) {
        L.push_back(t);
        t = A[t].next;
    }
    n = L.size();
    for (int i = 0; i < n; i++) {
        E[c].push_back(L[i]);
        cnt++;
        if (cnt == k && i != n - 1) {
            cnt = 0;
            c++;
        }
    }
    // 或者先整体翻转，size%k 翻转，再k个一组翻转
    for (int i = c; i >= 0; i--)
        for (auto it : E[i]) 
            ans.push_back(it);
    for (int i = 0; i < n - 1; i++) 
        printf("%05d %d %05d\n", ans[i], A[ans[i]].data, ans[i + 1]);
    printf("%05d %d -1", ans.back(), A[ans.back()].data);
    return 0;
}