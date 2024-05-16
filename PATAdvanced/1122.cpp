#include<iostream>
#include<set>
#include<vector>
using namespace std;

int e[210][210] = {0};


int main(){
    fill(e[0],e[0]+210*210,0);
    int n,m;
    cin >> n >> m;
    int t1,t2;
    for(int i = 0;i < m;i++){
        scanf("%d %d",&t1,&t2);
        e[t1][t2] = e[t2][t1] = 1;
    }
    // 简单环 无重复节点且经过了所有点 首尾相等，各节点相连 个数n+1 
    int k1,k2;
    cin >> k1;
    // 节点1-n 序号从1开始
    int exist[n+1];

    while(k1--){
        scanf("%d",&k2);
        int v[k2];

        fill(exist,exist+n+1,0);
        int t;
        for(int j = 0;j < k2;j++){
            scanf("%d",&t);
            v[j] = t;
            exist[t] = 1;
        }
        if(k2 != n+1 || v[0] != v[k2-1]){
            printf("NO\n");
            continue;
        }
        int flag = 0;
        for(int j = 1;j <= n;j++){
            if(exist[j] == 0){
                flag = 1;break;
            }
        }
        if(flag){
            printf("NO\n");
            continue;
        }
        for(int j = 0;j < k2 - 1;j++){
            if(e[v[j]][v[j+1]] == 0){
                flag = 1;
                break;
            }
        }
        if(flag){
            printf("NO\n");
        }else{
            printf("YES\n");
        }
    }
    return 0;
}