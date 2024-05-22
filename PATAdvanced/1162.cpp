#include<iostream>
#include<cstdio>
using namespace std;
const int N = 35;
string c[N];
int L[N],R[N];

// 自己想的
// 其中+，-两个符号既可以表示加减也可以表示正负，当表示正负的时候该节点一定是没有左孩子的
// 需要对有右孩子没有左孩子特殊处理
string dfs(int index){
    string left = "",right = "";
    if(L[index] == -1 && R[index] == -1) return c[index];
    if(L[index] != -1 && R[index] != -1){
        left = "(" + dfs(L[index]) + ")";
        right = "(" + dfs(R[index]) + ")";
        return left + right + c[index];
    }
    if(R[index] != -1){
        right = "(" + dfs(R[index]) + ")";
    }
    return c[index]+right;
}
// https://blog.csdn.net/liuchuo/article/details/126223594

int main(){
    int n,l,r;
    scanf("%d",&n);
    // 切记n从1开始
    int exist[n+1] = {0};
    for(int i = 1;i <= n;i++){
        cin >> c[i] >> l >> r;
        L[i] = l;
        R[i] = r;
        if(l != -1){
            exist[l] = 1;
        }
        if(r != -1){
            exist[r] = 1;
        }
    }
    int root = 1;
    // for(int i = 1;i <= n;i++){
    //     if(!exist[i]) {
    //         root = i;
    //         break;
    //     }
    // }
    while(exist[root])root++;
    cout << "(" + dfs(root) + ")";
    
    printf("\n");
    return 0;
}