#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
int n,l,m,k;
struct node {
    int id,layer;
};
vector<vector<int>> v;
int bfs(node n){
    bool visit[1010] = {false};
    queue<node> q;
    q.push(n);
    visit[n.id] = true;
    int cnt = 0;
    while(!q.empty()){
        node top = q.front();
        q.pop();
        int topid = top.id;
        for(int i = 0;i < v[topid].size();i++){
            int nextid = v[topid][i];
            if(!visit[nextid] && top.layer < l){
                node next = {nextid,top.layer + 1};
                q.push(next);
                visit[nextid] = true;
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    scanf("%d %d",&n,&l);
    v.resize(n + 1);
    for(int i = 1;i <= n;i++){
        scanf("%d",&m);
        for(int j = 0;j < m;j++){
            int temp;
            scanf("%d",&temp);
            v[temp].push_back(i);
        }
    }
    scanf("%d",&k);
    int tid;
    for(int i = 0;i < k;i++){
        scanf("%d",&tid);
        node t = {tid,0};
        printf("%d\n",bfs(t));
    }
    return 0;
}