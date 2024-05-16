#include<iostream>
#include<vector>
#include<unordered_set>
// https://blog.csdn.net/Weary_PJ/article/details/124965944
using namespace std;
int n,m,k;
struct edge{
    int a,b;
}edge[10001];
int colors[10001];

int main(){
    scanf("%d %d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d %d",&edge[i].a,&edge[i].b);
    }
    scanf("%d",&k);
    while(k--){
        for(int i = 0;i < n;i++){
            scanf("%d",&colors[i]);
        }
        bool res = true;
        for(int i = 0;i < m;i++){
            if(colors[edge[i].a] == colors[edge[i].b]) {
                res = false;
                break;
            }
        }
        if(res){
            unordered_set<int> s;
            for(int i = 0;i < n;i++){
                s.insert(colors[i]);
            }
            printf("%d-coloring\n",s.size());
        }else{
            printf("No\n");
        }
    }
}