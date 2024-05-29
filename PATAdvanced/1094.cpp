#include<iostream>
#include<vector>
#include<queue>
using namespace std;
// https://blog.csdn.net/liuchuo/article/details/52213503
vector<int> v[100];
int book[100];
void dfs(int index,int level){
    book[level]++;
    for(int child:v[index]){
        dfs(child,level+1);
    }
}

vector<int> children[100]; // 即上面的v[100]
// int level[100]; // 映射每个节点对应的层数


int main(){
    int n,m;
    int id,k;
    int t;
    scanf("%d %d",&n,&m);
    for(int i = 0;i < m;i++){
        scanf("%d %d",&id,&k);
        for(int j = 0;j < k;j++){
            scanf("%d",&t);
            v[id].push_back(t);
        }
    }
    dfs(1,1);
    int maxnum = 0,maxlevel = 1;
    for(int i = 1;i <= n;i++){
        if(book[i] > maxnum){
            maxnum = book[i];
            maxlevel = i;
        }
    }
    printf("%d %d",maxnum,maxlevel);
    // bfs(); 法二
    return 0;
}

void bfs() {
    int n, m, parent, numChildren, child;
    scanf("%d %d", &n, &m);

    // 构建家族树
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &parent, &numChildren);
        for (int j = 0; j < numChildren; ++j) {
            scanf("%d", &child);
            children[parent].push_back(child);
        }
    }

    queue<pair<int,int>> q;
    q.push({1,1}); // 从根节点开始BFS
    // level[1] = 1; // 根节点所在层为第一层
    int maxl = 1,maxcnt = 0;
    int cnt = 0;
    int curl = -1;
    while (!q.empty()) {
        int curr = q.front().first;
        int l = q.front().second;
        q.pop();
        // book[level[curr]]++; // 统计当前层的人数
        if(l != curl){
            cnt = 0;
            curl = l;
        }
        cnt++;
        if(cnt > maxcnt){
            maxcnt = cnt;
            maxl = l;
        }
        // 将当前节点的子节点加入队列，并更新子节点的层数
        for (int child : children[curr]) {
            // level[child] = level[curr] + 1;
            q.push({child,l+1});
        }
    }
    cout << maxcnt << " " << maxl;
}

