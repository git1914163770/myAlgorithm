#include<iostream>
#include<algorithm>
#include<climits>

using namespace std;
// 算法笔记P377
int n,m,c1,c2;
// num 路径数;weight 点的权重 e 边的权重
int weight[501],e[501][501],dis[501],num[510];
// 最大点权之和
int w[501];
bool visit[501];
const int inf = INT_MAX;
int main(){
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    for(int i = 0;i < n;i++)
        scanf("%d",&weight[i]);
    fill(e[0],e[0]+501*501,inf);
    fill(dis,dis + 501,inf);
    int a,b,c;
    for(int i = 0;i < m;i++){
        scanf("%d%d%d",&a,&b,&c);
        e[a][b] = e[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for(int i = 0;i < n;i++){
        int u = -1,minn = inf;
        for(int j = 0; j < n;j++){
            if(visit[j] == false && dis[j] < minn){
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0;v < n;v++){
            if(visit[v] == false && e[u][v] != inf){
                if(dis[u] + e[u][v] < dis[v]){
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                }else if(dis[u]+e[u][v] == dis[v]){
                    num[v] += num[u];
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];
                }
            }
        }
    }
    printf("%d %d",num[c2],w[c2]);
    return 0;
}