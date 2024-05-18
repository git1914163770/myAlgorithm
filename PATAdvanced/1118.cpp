// https://blog.csdn.net/Weary_PJ/article/details/125032759
// https://blog.csdn.net/liuchuo/article/details/52505109

#include<iostream>
#include<cstdio>
using namespace std;

const int N = 10010;
int n,idx,k;
int p[N],birds[N];

int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int main(){
    scanf("%d",&n);
    for(int i = 0;i < N;i++){
        p[i] = i;
    }
    int max_id = 1,cnt = 0;
    while(n--){
        scanf("%d",&k);
        for(int i = 0;i < k;i++){
            scanf("%d",&birds[i]);
            if(max_id < birds[i]) max_id = birds[i];
        }
        int pa = find(birds[0]);
        for(int i = 1;i < k;i++){
            int pb = find(birds[i]);
            if(pa != pb){
                p[pb] = pa;
                cnt++;
            }
        }
    }
    printf("%d %d\n",max_id - cnt,max_id);
    scanf("%d",&k);
    while(k--){
        int a,b;
        scanf("%d %d",&a,&b);
        if(find(a) == find(b)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
