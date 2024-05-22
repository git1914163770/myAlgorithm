#include<iostream>
#include<vector>
#include<cstdio>
#include<climits>
using namespace std;
const int N = 1005;
int e[N][N],dis[N];
bool visit[N] = {false};

const int inf = INT_MAX;


int main(){
    int n,m;
    fill(e[0],e[0] + N*N,inf);

    scanf("%d %d",&n,&m);
    int a,b,w,k;
    for(int i = 1;i <= m;i++){
        scanf("%d %d %d",&a,&b,&w);
        e[a][b] = w;
        e[b][a] = w;
    }
    scanf("%d",&k);
    int temp[n+1];
    while(k--){
        for(int j = 1;j <=n;j++){
            scanf("%d",&temp[j]);
        }
        fill(dis,dis+N,inf);
        dis[temp[1]] = 0;
        fill(visit,visit+N,false);
        bool flag = false;
        for(int i = 1;i <= n;i++){
            int u = -1,md = inf;
            for(int j = 1;j <= n;j++){
                if(!visit[j] && dis[j] < md){
                    md = dis[j];
                    u = j;
                }
            }
            if(dis[temp[i]] == dis[u]) u = temp[i];
            else{
                flag = true;
                break;
            }
            visit[u] = true;
            for(int v = 1;v <= n;v++){
                if(!visit[v] && e[u][v] != inf){
                    if(dis[u] + e[u][v] < dis[v]){
                        dis[v] = dis[u] + e[u][v];
                    }
                }
            }
        }
        if(flag) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}