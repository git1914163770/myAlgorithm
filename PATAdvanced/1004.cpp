#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<int> child[100];
int N,M;
int maxLevel,num_of_eachlevel[100]= {0};

void dfs(int curID,int curlevel){
    // 或者在main函数中使用这段代替
    // for(maxLevel = 99;maxLevel > 0;maxLevel--){
    //     if(num_of_eachlevel[maxLevel] != 0) break;
    // }
    if(curlevel > maxLevel) maxLevel = curlevel;
    
    if(child[curID].size() > 0){
        for(auto x : child[curID]){
            dfs(x,curlevel + 1);
        }
    }else{
        num_of_eachlevel[curlevel]++;
    }
}

void bfs(){
    queue<pair<int, int>> q;
    q.push({1,1});

    while (!q.empty()) {
        int curID = q.front().first;
        int curLevel = q.front().second;
        q.pop();

        if (curLevel > maxLevel) maxLevel = curLevel;

        if (child[curID].empty()) {
            num_of_eachlevel[curLevel]++;
        } else {
            for (auto x : child[curID]) {
                q.push({x, curLevel + 1}); // 将邻居节点和层数入队
            } 
        }
    }
}

int main(){
    int i,j,k;
    cin >> N >> M;
    for(int i = 0;i < M;i++){
        int id,k;
        cin >> id >> k;
        while(k--){
            cin >> j;
            child[id].push_back(j);
        }
    }
    // dfs(1,1);
    bfs();

    for(int i = 1;i <= maxLevel;i++){
        if(i!=1) cout << " ";
        cout << num_of_eachlevel[i];
    }
    return 0;
}