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
    return 0;
}

vector<int> children[100]; // 即上面的v[100]
int level[100]; // 映射每个节点对应的层数

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

    queue<int> q;
    q.push(1); // 从根节点开始BFS
    level[1] = 1; // 根节点所在层为第一层

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        book[level[curr]]++; // 统计当前层的人数

        // 将当前节点的子节点加入队列，并更新子节点的层数
        for (int child : children[curr]) {
            level[child] = level[curr] + 1;
            q.push(child);
        }
    }

    int maxPopulation = 0, maxGeneration = 1;
    // 找出人数最多的一代
    for (int i = 1; i < 100; ++i) {
        if (book[i] > maxPopulation) {
            maxPopulation = book[i];
            maxGeneration = i;
        }
    }

    printf("%d %d", maxPopulation, maxGeneration);
}
