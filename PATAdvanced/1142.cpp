//一个团是无向图中的顶点子集，其中每两个不同的顶点都是相邻的。
// 一个极大团是指不能通过包括一个更多相邻顶点来扩展的团。
// 通俗地说，一个团就是一群人，彼此之间都是朋友。
// 而极大团则是指这个朋友圈已经是最大的了，再加入其他人就无法满足所有人之间都是朋友的条件了。

#include<iostream>
#include<vector>

using namespace std;

int e[210][210];

int main(){
    int nv,ne,m,a,b,k;
    scanf("%d %d",&nv,&ne);
    for(int i = 0;i < ne;i++){
        scanf("%d %d",&a,&b);
        e[a][b] = e[b][a] = 1;
    }
    scanf("%d",&m);
    for(int i = 0;i < m;i++){
        scanf("%d",&k);
        int v[k];
        int hash[210] = {0},isclique = 1,isMaximal = 1;
        for(int j = 0;j < k;j++){
            scanf("%d",&v[j]);
            hash[v[j]] = 1;
        }
        for(int j = 0;j < k;j++){
            for(int l = j + 1;l < k;l++){
                if(e[v[j]][v[l]] == 0){
                    isclique = 0;
                    break;
                }
            }
            if(isclique == 0) break;
        }
        if(isclique == 0){
            printf("Not a Clique\n");
            continue;
        }
        for(int j = 1;j <= nv;j++){
            if(hash[j] != 0) continue;
            int l;
            for(l = 0;l < k;l++){
                if(e[v[l]][j] == 0) break;
            }
            if(l == k){
                isMaximal = 0;
                break;
            }
        }
        if(isMaximal == 1){
            printf("Yes\n");
        }else{
            printf("Not Maximal\n");
        }
    }

    return 0;
}
