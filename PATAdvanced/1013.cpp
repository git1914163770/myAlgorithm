#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int v[1010][1010];
bool visit[1010];
int n;
void dfs(int node){
    visit[node] = true;
    for(int i = 0;i < n;i++){
        if(!visit[node] && v[node][i] == 1){
            dfs(i);
        }
    }
}

// 求连通分量
int main(){
    int m,k,a,b;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0;i < m;i++){
        scanf("%d%d",&a,&b);
        v[a][b] = v[b][a] = 1;
    }
    for(int i = 0;i < k;i++){
        fill(exist,exist+n,false);
        scanf("%d",&a);
        int cnt = 0;
        visit[a] = true;
        for(int j = 1;j <= n;j++){
            if(visit[j] == false){
                cnt++;
                dfs(j);
            }
        }
        printf("%d\n",cnt - 1);
    }
    return 0;
}