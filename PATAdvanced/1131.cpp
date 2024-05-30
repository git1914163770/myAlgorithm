#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<vector<int>> v(10000);
int visit[10000], minCnt, minTransfer, start, end1;
unordered_map<int, int> line;
vector<int> path, tempPath;
int transferCnt(vector<int> a) {
    int cnt = -1, preLine = 0;
    for (int i = 1; i < a.size(); i++) {
        if (line[a[i-1]*10000+a[i]] != preLine) cnt++;
        preLine = line[a[i-1]*10000+a[i]];
    }
    return cnt;
}
void dfs(int node, int cnt) {
    if (node == end1){
        if(cnt < minCnt || (cnt == minCnt && transferCnt(tempPath) < minTransfer)) {
            minCnt = cnt;
            minTransfer = transferCnt(tempPath);
            path = tempPath;
        }
        return;
    } 
    for (int i = 0; i < v[node].size(); i++) {
        if (visit[v[node][i]] == 0) {
            visit[v[node][i]] = 1;
            tempPath.push_back(v[node][i]);
            dfs(v[node][i], cnt + 1);
            visit[v[node][i]] = 0;
            tempPath.pop_back();
        }
    }
}
int main() {
    int n, m, k, pre, temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &m, &pre);
        for (int j = 1; j < m; j++) {
            scanf("%d", &temp);
            v[pre].push_back(temp);
            v[temp].push_back(pre);
            line[pre*10000+temp] = line[temp*10000+pre] = i + 1;
            pre = temp;
        }
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &start, &end1);
        minCnt = 99999, minTransfer = 99999;
        tempPath.clear();
        tempPath.push_back(start);
        visit[start] = 1;
        dfs(start, 0);
        visit[start] = 0;
        printf("%d\n", minCnt);
        int preLine = line[path[0]*10000+path[1]],preTransfer = start;
        for(int j = 1;j < path.size() - 1;j++){
            if(line[path[j]*10000+path[j+1]]!=preLine){
                // 在转站时打印上一条信息
                printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[j]);
                preLine = line[path[j]*10000+path[j+1]];
                preTransfer = path[j];
            }
        }
        // 结束时打印剩下的（最后未转站，所以上面没打印）
        printf("Take Line#%d from %04d to %04d.\n", preLine, preTransfer, path[path.size()-1]);
    }
    return 0;
}