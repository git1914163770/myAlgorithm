#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> parent,cntCycle;
int find(int x){
    if(x != parent[x]) parent[x] = find(parent[x]);
    return parent[x];
}

int cmp1(int a, int b){
    return a > b;
}

void Union(int a,int b){
    int fA = find(a);
    int fB = find(b);
    if(fA != fB){
        parent[fA] = fB; 
    }
}

int main(){
    int n,k,t;
    // hash 记录课程对应的第一个id，用于union
    int course[1001];
    fill(course,course+1001,0);
    scanf("%d",&n);
    // 下标1-n
    parent.resize(n + 1);
    cntCycle.resize(n + 1);
    // 初始化
    for(int i = 1;i <= n;i++)
        parent[i] = i;
    for(int i = 1;i <= n;i++){
        scanf("%d:",&k);
        for(int j = 0;j < k;j++){
            scanf("%d",&t);
            if(course[t] == 0)
                course[t] = i;
            else Union(i,course[t]);
        }
    }
    for(int i = 1;i <= n;i++){
        cntCycle[find(i)]++;
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        if(cntCycle[i] != 0) cnt++;
    }
    printf("%d\n",cnt);
    sort(cntCycle.begin(),cntCycle.end(),greater<int>());
    for(int i = 0;i < cnt;i++){
        if(i != 0) printf(" ");
        printf("%d",cntCycle[i]);
    }
    return 0;
}