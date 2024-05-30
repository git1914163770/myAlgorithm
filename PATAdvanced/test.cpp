#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;
int n,m,st,ed;

int e1[510][510],e2[510][510];
int dist[510],time[510];
bool visit[510] = {false};
vector<int> temppath,respath;
vector<int> pre[510];
const int inf = INT_MAX;
int timemin = INT_MAX,nodenum = INT_MAX;

void dfs(int v){
    temppath.push_back(v);
    if(v == st){
        int value = 0;
        for(int i = temppath.size() - 1;i > 0;i--){
            int id = temppath[i],idnext = temppath[i-1];
            value+=e2[id][idnext];
        }
        if(value < timemin){
            timemin = value;
            path = temppath;
        }
        temppath.pop_back();
    }
    for(int i = 0;i < pre[v].size();i++){
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}

int main(){
    fill(e1[0],e1[0]+510*510,inf);
    fill(e2[0],e2[0]+510*510,inf);
    fill(dist,dist+510,inf);
    fill(time,time+510,inf);
    scanf("%d %d",&n,&m);
    int a,b,flag,len,t;
    for(int i = 0;i < m;i++){
        scanf("%d %d %d %d %d",&a,&b,&flag,&len,&t);
        e1[a][b] = len;
        e2[a][b] = t;
        if(flag != 1){
            e1[b][a] = len;
            e2[b][a] = len;
        }
    }
    scanf("%d %d",&st,&ed);
    dist[st] = 0;
    time[st] = 0;
    for(int i = 0;i < n;i++){
        int u = -1,minn = inf;
        for(int j = 0;j < n;j++){
            if(dist[j] < minn && !visit[j]){
                u = j;
                minn = dist[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0;v < n;v++){
            if(!visit[v] && e1[u][v] != inf){
                if(dist[u]+e1[u][v] < dist[v]){
                    dist[v] = dist[u] + e1[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(dist[u] + e1[u][v] == dist[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
    dfs(ed);
    printf("%d ",dist[ed]);
    for(int i = path.size()-1;i >= 0;i--){
        printf("%d",path[i]);
        if(i != 0) printf(" -> ");
    }
    return 0;
}