#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include<climits>

using namespace std;

int e[205][205],dis[205];
int weight[205];// 点权
bool visit[205];
vector<int> pre[205];
vector<int> temppath,path;
const int inf = INT_MAX;
int n,k;
// 字符串对应的数字映射和数字对应的字符串
map<string,int> m;
map<int,string> m2;

int maxvalue = 0, mindepth, cntpath = 0;
double maxavg;
void dfs(int v) {
    temppath.push_back(v);
    if(v == 0) {
        int value = 0;
        for(int i = 0; i < temppath.size(); i++) {
            value += weight[temppath[i]];
        }
        double tempavg = 1.0 * value / (temppath.size() - 1);
        if(value > maxvalue) {
            maxvalue = value;
            maxavg = tempavg;
            path = temppath;
        } else if(value == maxvalue && tempavg > maxavg) {
            maxavg = tempavg;
            path = temppath;
        }
        temppath.pop_back();
        cntpath++;
        return ;
    }
    for(int i = 0; i < pre[v].size(); i++) {
        dfs(pre[v][i]);
    }
    temppath.pop_back();
}
int main() {
    fill(e[0], e[0] + 205 * 205, inf);
    fill(dis, dis + 205, inf);
    scanf("%d %d", &n, &k);
    string s;
    cin >> s;
    m[s] = 0;
    m2[0] = s;
    for(int i = 1; i < n; i++) {
        cin >> s >> weight[i];
        m[s] = i;
        m2[i] = s;
    }
    string sa, sb;
    int temp;
    for(int i = 0; i < k; i++) {
        cin >> sa >> sb >> temp;
        e[m[sa]][m[sb]] = temp;
        e[m[sb]][m[sa]] = temp;
    }
    pre[0].push_back(0);
    dis[0] = 0;
    for(int i = 0; i < n; i++) {
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && e[u][v] != inf) {
                if(dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if(dis[v] == dis[u] + e[u][v]) {
                    pre[v].push_back(u);
                }
            }
        }
    }
    int rom = m["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n", cntpath, dis[rom], maxvalue, (int)maxavg);
    for(int i = path.size() - 1; i >= 1; i--) {
        cout << m2[path[i]] << "->";
    }
    cout << "ROM";
    return 0;
}