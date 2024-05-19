#include<iostream>
#include<vector>
// lc LCR 046. 二叉树的右视图
// https://blog.csdn.net/liuchuo/article/details/134378874
// dfs 递归 层数+1 记录该层下第一个节点
// bfs 每个节点新增depth，不断更新该depth下节点属性
using namespace std;

int N,pre[30],in[30],t[30];
int maxlevel = -1;
void dfs(int ins,int ine,int pres,int level){
    if(ins > ine) return;
    if(level > maxlevel) maxlevel = level;
    if(t[level] == 0) t[level] = pre[pres];
    int pos = ins;
    while(in[pos] != pre[pres]) pos++;
    dfs(ins,pos-1,pres+1,level+1);
    dfs(pos+1,ine,pres+pos-ins+1,level+1);
}
int main(){
    cin >> N;
    for(int i = 1;i <= N;i++) cin >> in[i];
    for(int i = 1;i <= N;i++) cin >> pre[i];
    dfs(1,N,1,1);
    for(int i = 1;i <= maxlevel;i++){
        if(i != 1) cout << " ";
        cout << t[i];
    }
    return 0;
}