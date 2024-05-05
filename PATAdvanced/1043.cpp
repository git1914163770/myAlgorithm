#include <cstdio>
#include <vector>
using namespace std;
bool isMirror;
vector<int> pre, post;
// https://blog.csdn.net/liuchuo/article/details/52160455
void getpost(int root, int tail) {
    if(root > tail) return ;
    int i = root + 1, j = tail;
    if(!isMirror) {
        while(i <= tail && pre[root] > pre[i]) i++;
        j = i;
        while(j <= tail && pre[root] <= pre[j]) j++;
    } else {
        while(i <= tail && pre[root] <= pre[i]) i++;
        j = i;
        while(j <= tail && pre[root] > pre[j]) j++;
    }
    if(j <= tail) return;
    getpost(root + 1, i - 1);
    getpost(i, tail);
    post.push_back(pre[root]);
}
int main() {
    int n;
    scanf("%d", &n);
    pre.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    getpost(0, n - 1);
    if(post.size() != n) {
        isMirror = true;
        post.clear();
        getpost(0, n - 1);
    }
    if(post.size() == n) {
        printf("YES\n%d", post[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", post[i]);
    } else {
        printf("NO");
    }
    return 0;
}