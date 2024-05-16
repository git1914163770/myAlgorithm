// 城市1-N 距离不超100
// https://blog.csdn.net/liuchuo/article/details/82560843
// 访问图中所有的点，且点之间有连接，且首尾相等 TS；数量为N+1，即无环 simple 
#include<iostream>
#include<vector>
#include<set>
#include<climits>
using namespace std;
int e[210][210],n,m;
int minn = INT_MAX;
int minID;
void check(int index){
    int sum = 0,flag = 1,cnt;
    scanf("%d",&cnt);
    set<int> s;
    int v[cnt];
    for(int i = 0;i < cnt;i++){
        scanf("%d",&v[i]);
        s.insert(v[i]);
    }
    for(int i = 0;i+1 < cnt;i++){
        if(e[v[i]][v[i+1]] == 0) {
            flag = 0;
            break;
        }
        sum += e[v[i]][v[i+1]];
    }
    if(flag == 0){
        printf("Path %d: NA (Not a TS cycle)\n", index);
    }else if(v[0] != v[cnt - 1] || s.size() != n){
        printf("Path %d: %d (Not a TS cycle)\n", index, sum);
    }else if(cnt != n + 1){
        printf("Path %d: %d (TS cycle)\n", index, sum);
        if (sum < minn) {
            minn = sum;
            minID = index;
        }
    }else {
        printf("Path %d: %d (TS simple cycle)\n", index, sum);
        if (sum < minn) {
            minn = sum;
            minID = index;
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    int a,b,c;
    for(int i = 0;i < m;i++){
        scanf("%d%d%d",&a,&b,&c);
        e[a][b] = e[b][a] = c;
    }
    int k;
    scanf("%d",&k);
    for(int i = 1;i <= k;i++) check(i);
    printf("Shortest Dist(%d) = %d\n", minID, minn);
    return 0;
}