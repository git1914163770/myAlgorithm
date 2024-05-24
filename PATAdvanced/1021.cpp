#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;

vector<int> node[10005];
bool visit[10005] = {false};
int n;

// 自己想的
int dfs(int s){
    visit[s] = true;
    if(node[s].size() == 0) return 1;
    int d = 0;
    for(int i = 0;i < node[s].size();i++){
        if(!visit[node[s][i]])
            d = max(d,dfs(node[s][i]));
    }
    return d+1;
}

// 其他方法：第一次 dfs找到距离第一个点为根的最深的点，第二次就是从这个最深的点为根看看其他的深度
// https://blog.csdn.net/liuchuo/article/details/52294178
// 其他方法 并查集 int cnt = n;合并之后连通块的数量-1
// https://blog.csdn.net/qq_46527915/article/details/120264502
int main(){
    scanf("%d",&n);
    int a,b;
    for(int i = 1;i<=n;i++){
        scanf("%d %d",&a,&b);
        node[a].push_back(b);
        node[b].push_back(a);
    }
    int res[n+1];
    int deep = -1;
    fill(res,res+n+1,0);
    for(int i = 1;i <= n;i++){
        fill(visit,visit+1+n,false);
        res[i] = dfs(i);
        deep = max(res[i],deep);
    }
    fill(visit,visit+1+n,false);
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(!visit[i]){
            dfs(i);
            cnt++;
        }
    }
    if(cnt >= 2){
        printf("Error: %d components",cnt);
        return 0;
    }
    for(int i = 1;i <= n;i++){
        if(res[i] == deep)
            printf("%d\n",i);
    }
    // 或者使用下面的方法
    // if(len>max_len)
    // {
    //     max_len=len;
    //     ans.clear();
    //     ans.push_back(i);
    // }else if(len==max_len) ans.push_back(i);
    
    return 0;
}