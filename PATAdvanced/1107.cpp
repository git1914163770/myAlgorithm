#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// isRoot用来统计一个集合下节点数量，
// 并统计有多少集合
vector<int> p,isRoot;
int cmp(int a,int b){
    return a > b;
}

int find(int x){
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

int cc; // union 次数

void Union(int a,int b){
    int faA = find(a);
    int faB = find(b);
    if(faA != faB){
        p[faA] = faB;
        // cc++;
    }
}

int main(){
    int n,k,t,cnt = 0;
    // hash 记录课程对应的第一个id，用于union
    int course[1001] = {0};
    scanf("%d",&n);
    // 下标1-n
    p.resize(n + 1);
    isRoot.resize(n + 1);
    for(int i = 1;i <= n;i++){
        p[i] = i;
    }
    for(int i = 1;i <= n;i++){
        scanf("%d:",&k);
        for(int j = 0;j < k;j++){
            scanf("%d",&t);
            if(course[t] == 0){
                course[t] = i;
            }
            Union(i,find(course[t]));
        }
    }
    // cout << n - cc <<endl; 集群个数
    // 找到每个节点的根节点，对应位置上数量++
    for(int i = 1; i <= n;i++){
        isRoot[find(i)]++;
    }
    for(int i = 1;i <= n;i++){
        if(isRoot[i] != 0){
            cnt++;
        }
    }
    printf("%d\n",cnt);
    sort(isRoot.begin(),isRoot.end(),cmp);
    for(int i = 0;i < cnt;i++){
        if(i!=0)printf(" ");
        printf("%d",isRoot[i]);
    }
    return 0;
}