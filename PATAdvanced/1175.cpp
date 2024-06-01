#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<climits>
using namespace std;
// 使用In2 是因为拓扑排0序会对每次入队的度-1，需要有个保存的
// 使用虚拟节点作为汇点，就转换为了单源最短路径问题
// https://blog.csdn.net/suiyuewushengly/article/details/120201425
// https://blog.csdn.net/weixin_55252589/article/details/135442248
int n,m,k,in[1005],in2[1005];
// 如果超过1000 可以考虑用邻接矩阵或map a*c+b映射
int e[1005][1005];
int weight[1005][1005];
int dist[1005];
vector<int> pre[1005];
vector<int> temppath,path;
const int inf = INT_MAX;
bool visit[1005] = {false};
int maxvoucher = INT_MIN;
bool circle(){
    int num = 0;
    queue<int> q;
    for(int i = 0;i < n;i++){
        if(in2[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        num++;
        q.pop();
        for(int i = 0;i < n;i++){
            if(e[u][i] != inf){
                in2[i]--;
                if(in2[i] == 0){
                    q.push(i);
                }
            }
        }
    }
    return num == n;
}

void dfs(int v){
    temppath.push_back(v);
    if(v == n){
        int value = 0;
        for(int i = temppath.size() - 1;i > 0;i--){
            int id = temppath[i],idnext = temppath[i-1];
            value+=weight[id][idnext];
        }
        if(value > maxvoucher){
            maxvoucher = value;
            path = temppath;
        }
        temppath.pop_back();
        return;
    }
    for(int i = 0;i < pre[v].size();i++){
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}

void dijkstra(){
    for(int i = 0;i < n + 1;i++){
        int u = -1,minn = inf;
        for(int j = 0;j < n + 1;j++){
            if(dist[j] < minn && !visit[j]){
                u = j;
                minn = dist[j];
            }
        }
        visit[u] = true;
        for(int v = 0;v < n + 1;v++){
            if(!visit[v] && e[u][v] != inf){
                if(dist[u] + e[u][v] < dist[v]){
                    dist[v] = dist[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dist[v] == dist[u] + e[u][v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
}

int main(){
    fill(e[0],e[0]+1005*1005,inf);
    fill(weight[0],weight[0]+1005*1005,0);
    fill(dist,dist+1005,inf);
    scanf("%d %d",&n,&m);
    int a,b,s,d;
    for(int i = 0;i < m;i++){
        scanf("%d %d %d %d",&a,&b,&s,&d);
        e[a][b] = s;
        weight[a][b] = d;
        in[b]++;
        in2[b]++;
    }
    bool f = circle();
    if(!f) printf("Impossible.\n");
    else{
        printf("Okay.\n");
        int st = n;
        for(int i = 0;i < n;i++){
            if(in[i] == 0){
                e[n][i] = 0;
                weight[n][i] = 0;
            }
        }
        dist[n] = 0;
        dijkstra();
    }
    scanf("%d",&k);
    int t;
    for(int i = 0;i < k;i++){
        scanf("%d",&t);
        if(in[t] == 0){
            printf("You may take test %d directly.\n",t);
        }else{
            if(!f){
                printf("Error.\n");
                continue;
            }
            temppath.clear();
            maxvoucher = INT_MIN;
            dfs(t);
            for(int i = path.size() - 2;i >= 0;i--){
                printf("%d",path[i]);
                if(i != 0)printf("->");
            }
            printf("\n");
        }
    }
    return 0;
}