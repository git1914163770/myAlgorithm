// 顶点均为偶数度的连通图
// 正好有两个奇数度的顶点

#include<iostream>
#include<vector>

using namespace std;

vector<int> v[510];

int cnt = 0;
int visited[510];
void dfs(int i){
    cnt++;
    visited[i] = 1;
    for(int child:v[i]){
        if(!visited[child]) dfs(child);
    }
}

int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0;i < k;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int even = 0;
    for(int i = 1;i <= n;i++){
        if(i > 1) printf(" ");
        if(v[i].size() % 2 == 0) even++;
        printf("%d",v[i].size());
    }
    printf("\n");
    dfs(1);
    if(cnt == n && even == n){
        printf("Eulerian");
    }else if(cnt == n && even == n - 2){
        printf("Semi-Eulerian");
    }else{
        printf("Non-Eulerian");
    }
    
    return 0;
}