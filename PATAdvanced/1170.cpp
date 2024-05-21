#include<iostream>
#include<vector>
#include<cstdio>
#include<set>
using namespace std;

vector<int> g[505];
int weight[505];

// 自己想的，邻接表法
int main(){
    int n,r,k;
    scanf("%d %d %d",&n,&r,&k);
    int u,v;
    while(r--){
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        // 其实下面这行可以注释
        g[v].push_back(u);
    }
    int m,a;
    scanf("%d",&m);
    while(m--){
        fill(weight,weight+n+1,0);
        set<int> s;
        for(int i = 1;i <= n;i++){
            scanf("%d",&a);
            weight[i] = a;
            s.insert(a);
        }
        if(s.size() > k) printf("Error: Too many species.\n");
        else if(s.size() < k) printf("Error: Too few species.\n");
        else {
            int flag = 1;
            for(int i = 1;i <= n;i++){
                for(auto node:g[i]){
                    if(weight[node] == weight[i]){
                        flag = 0;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(!flag) printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}
// 邻接矩阵 https://blog.csdn.net/liuchuo/article/details/134353821