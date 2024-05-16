#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

vector<int> e[10001];

int main(){
    int n,m,k;
    cin >> n >> m;
    int a,b;
    for(int i = 0;i < m;i++){
        scanf("%d %d",&a,&b);
        // 注意存的是边的编号，不是邻接表
        e[a].push_back(i);
        e[b].push_back(i);
    }
    scanf("%d",&k);
    while(k--){
        int z;
        scanf("%d",&z);
        int points[z];
        for(int i = 0;i < z;i++){
            scanf("%d",&points[i]);
        }
        int visited[m];
        fill(visited,visited+m,0);
        for(int point:points){
            for(int c:e[point]){
                visited[c] = true;
            }
        }
        int flag = 0;
        for(int i = 0;i < m;i++){
            if(!visited[i]){
                cout << "No\n";
                flag = 1;
                break;
            }
        }
        if(!flag) cout << "Yes\n";
        // else cout << "No\n";
    }
    return 0;
}