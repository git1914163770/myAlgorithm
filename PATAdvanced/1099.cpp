// https://blog.csdn.net/liuchuo/article/details/52181651
// 类似 1064

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, cnt, b[100], maxLevel;
struct node {
    int data, l, r;
}a[110];
vector<int> v[100];
// 这里不能使用参数index index*2和index*2+1 
// 然后靠map排序，因为100个节点，最多可能100层，index可能超过int上限
void dfs(int root, int level) {
    maxLevel = max(level, maxLevel);
    if (a[root].l != -1) dfs(a[root].l, level + 1);
    a[root].data = b[cnt++];
    if (a[root].r != -1) dfs(a[root].r, level + 1);
}
// 法一 建树完后层序遍历
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i].l >> a[i].r;
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(b, b + n);
    dfs(0, 0);
    v[0].push_back(0);
    for (int i = 0; i <= maxLevel; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (i != 0) cout << " ";
            cout << a[v[i][j]].data;
            if(a[v[i][j]].l != -1) v[i+1].push_back(a[v[i][j]].l);
            if(a[v[i][j]].r != -1) v[i+1].push_back(a[v[i][j]].r);
        }
    }
    return 0;
}

// 法二 
// int n,L[105],R[105],c=0,v[105];
// vector<pair<int,int> >a;
// void dfs(int p,int index){
//     if(p==-1) return;
//     dfs(L[p],index+1);
//     a.push_back(make_pair(index,v[c++]) );
//     dfs(R[p],index+1);
// }
// int main(){
//    scanf("%d",&n);
//    for(int i = 0; i < n; i++) scanf("%d %d",&L[i],&R[i]);
//    for(int i = 0; i < n; i++) scanf("%d",&v[i]);
//    sort(v,v+n);
//    dfs(0,1);
//    // 层数小的排前面，因为二叉搜索树的性质，同一层的元素从左往右依次增大 
//    sort(a.begin(),a.end());
//    for(int i = 0; i < a.size(); i++) printf("%s%d",i?" ":"",a[i].second);
//    return 0;
// }