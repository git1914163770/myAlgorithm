#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int pre[50001], in[50001];
bool flag = false;
unordered_map<int,int> m;
// https://blog.csdn.net/Weary_PJ/article/details/124887235
void postOrder(int prel, int inl, int inr) {
    if (inl > inr || flag == true) return;
    int i = m[pre[prel]];
    postOrder(prel+1, inl, i-1);
    postOrder(prel+i-inl+1, i+1, inr);
    if (flag == false) {
        printf("%d", in[i]);
        flag = true;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++){
        scanf("%d", &in[i]);
        m[in[i]] = i;
    }
    postOrder(0, 0, n-1);
    return 0;
}