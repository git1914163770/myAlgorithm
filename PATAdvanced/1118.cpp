#include<iostream>
#include<vector>
#include<cstdio>
// https://blog.csdn.net/Weary_PJ/article/details/125032759
// https://blog.csdn.net/liuchuo/article/details/52505109
using namespace std;
int n;
const int N = 10010;
int p[N],cntbird[N];
bool visit[N] = {false};
int find(int x){
    if(p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void Union(int a, int b){
    int fA = find(a);
    int fB = find(b);
    if(fA!=fB) p[fA] = fB;
}

int main(){
    for(int i = 0;i < N;i++){
        p[i] = i;
    }
    scanf("%d",&n);
    int k;
    for(int i = 0;i < n;i++){
        scanf("%d",&k);
        int a,b;
        if(k != 0) {
            scanf("%d",&a);
            visit[a] = true;
        }
        for(int j = 1;j < k;j++){
            scanf("%d",&b);
            visit[b] = true;
            Union(a,b);
        }
    }
    int cnt = 0,sum = 0;
    for(int i = 0;i < N;i++){
        if(visit[i]){
            sum++;
            cntbird[find(i)]++;
        }
    }

    for(int i = 0;i < N;i++){
        if(cntbird[i] != 0){
            cnt++;
            // sum += cntbird[i];
        }
    }
    printf("%d %d\n",cnt,sum);
    int a,b;
    scanf("%d",&k);
    while(k--){
        scanf("%d %d",&a,&b);
        if(find(a) == find(b)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}