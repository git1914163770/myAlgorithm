#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include<climits>

using namespace std;
int n,m,st,ed;

int e1[510][510],e2[510][510];
int dist[510],fastpath[510];
bool visit[510] = {false};
vector<int> temppath,path,path2;
vector<int> pre[510];
const int inf = INT_MAX;
int timemin = INT_MAX,nodenum = INT_MAX;
int globalflag = 0;
// 求最短路径（如果相同求时间最短的那条），一个求最快路径（如果相同求结点数最小的那条）
void dfs(int v){
    temppath.push_back(v);
    if(v == st){
        if(globalflag == 0){
            int value = 0;
            for(int i = temppath.size() - 1;i > 0;i--){
                int id = temppath[i],idnext = temppath[i-1];
                value+=e2[id][idnext];
            }
            if(value < timemin){
                timemin = value;
                path = temppath;
            }
        }else{
            if(temppath.size() < nodenum){
                nodenum = temppath.size();
                path2 = temppath;
            }
        }
        temppath.pop_back();
        // 记得return
        return;
    }
    for(int i = 0;i < pre[v].size();i++){
        // cout << pre[v][i] << "hh";
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}

int main(){
    fill(e1[0],e1[0]+510*510,inf);
    fill(e2[0],e2[0]+510*510,inf);
    fill(dist,dist+510,inf);
    fill(fastpath,fastpath+510,inf);
    scanf("%d %d",&n,&m);
    int a,b,flag,len,t;
    for(int i = 0;i < m;i++){
        scanf("%d %d %d %d %d",&a,&b,&flag,&len,&t);
        e1[a][b] = len;
        e2[a][b] = t;
        if(flag != 1){
            e1[b][a] = len;
            e2[b][a] = t;
        }
    }
    scanf("%d %d",&st,&ed);
    dist[st] = 0;
    for(int i = 0;i < n;i++){
        int u = -1,minn = inf;
        for(int j = 0;j < n;j++){
            if(dist[j] < minn && !visit[j]){
                u = j;
                minn = dist[j];
            }
        }
        if(u == -1) break;
        // 记得visit[u] = true;
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
    // 一定要重新初始化visit
    fill(visit,visit+510,false);
    fastpath[st] = 0;
    temppath.clear();
    for(int i = 0;i < n;i++){
        int u = -1,minn = inf;
        for(int j = 0;j < n;j++){
            if(fastpath[j] < minn && !visit[j]){
                u = j;
                minn = fastpath[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0;v < n;v++){
            if(!visit[v] && e2[u][v] != inf){
                if(fastpath[u]+e2[u][v] < fastpath[v]){
                    fastpath[v] = fastpath[u] + e2[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                }else if(fastpath[u] + e2[u][v] == fastpath[v]){
                    pre[v].push_back(u);
                }
            }
        }
    }
    globalflag = 1;
    dfs(ed);
    if(path == path2){
        printf("Distance = %d; Time = %d: ",dist[ed],fastpath[ed]);
        for(int i = path.size()-1;i >= 0;i--){
            printf("%d",path[i]);
            if(i != 0) printf(" -> ");
        }
    }else{
        printf("Distance = %d: ",dist[ed]);
        for(int i = path.size()-1;i >= 0;i--){
            printf("%d",path[i]);
            if(i != 0) printf(" -> ");
        }
        printf("\nTime = %d: ",fastpath[ed]);
        for(int i = path2.size()-1;i >= 0;i--){
            printf("%d",path2[i]);
            if(i != 0) printf(" -> ");
        }
    }
    return 0;
}