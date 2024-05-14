#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// https://blog.csdn.net/zxc0074869/article/details/122786262
// 邻接矩阵 https://blog.csdn.net/Weary_PJ/article/details/124935543
const int maxn = 110;
struct node{
    int weight;
    vector<int> child;
} Node[maxn];

int n,m,s;
vector<int> path;
vector<vector<int>> ans;

void DFS(int index,vector<int> path,int sum){
    if(sum > s) return;
    if(sum == s){
        if(Node[index].child.size() != 0) return ;
        ans.push_back(path);
        return;
    }
    for(int i = 0;i < Node[index].child.size();i++){
        int child = Node[index].child[i];
        path.push_back(Node[child].weight);
        DFS(child,path,sum + Node[child].weight);
        path.pop_back();
    }
}

bool compareVector(const vector<int>& a, const vector<int>& b) {
    // 比较两个vector的大小，按降序排序
    return a > b;
}

int main(){
    scanf("%d %d %d",&n,&m,&s);
    for(int i = 0;i < n;i++){
        scanf("%d",&Node[i].weight);
    }
    int id,k,child;
    for(int i = 0;i < m;i++){
        scanf("%d %d",&id,&k);
        for(int j = 0;j < k;j++){
            scanf("%d",&child);
            Node[id].child.push_back(child);
        }
    }
    path.push_back(Node[0].weight);
    DFS(0,path,Node[0].weight);
    // sort(ans.begin(),ans.end(),greater<vector<int>>());
    sort(ans.begin(),ans.end(),compareVector);
    for (int i = 0; i < ans.size(); i++) {
        printf("%d", ans[i][0]);
        for (int j = 1; j < ans[i].size(); j++) {
            printf(" %d", ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}