// 暴力？并查集？
// for i in 1-n:
//  for(v in vector){
//      if(!e[i][v]) break;
//  }

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int A[205][205];

int main(){
    int n,e,a,b,k;
    scanf("%d %d",&n,&e);
    for(int i = 0;i < e;i++){
        scanf("%d %d",&a,&b);
        A[a][b] = A[b][a] = 1;
    }
    scanf("%d",&k);
    for(int area = 1;area <= k;area++){
        int l,m;
        scanf("%d",&l);
        vector<int> v(l);
        for(int i = 0;i < l;i++){
            scanf("%d",&v[i]);
        }
        // 检查是否互相为好友
        int f = 0;
        for(int i = 0;i < l;i++){
            for(int j = i +1;j < l;j++){
                if(!A[v[i]][v[j]]) {
                    f = 1;
                    break;
                }
            }
            if(f == 1) break;
        }
        if(f){
            printf("Area %d needs help.\n",area);
            continue;
        }
        int f2,t;
        for(int i = 1;i <= n;i++){
            f2 = 1;
            for(auto c:v){
                // 不加c==i也可以 因为A[i][i] == 0
                if(!A[i][c] || c == i){
                    f2 = 0;
                    break;
                }
            }
            if(f2 == 1){
                t = i;
                break;
            }
        }
        if(f2 == 1){
            printf("Area %d may invite more people, such as %d.\n",area,t);
        }else{
            // 全部检查完
            printf("Area %d is OK.\n",area);
        }
    }
    return 0;
}