//https://blog.csdn.net/liuchuo/article/details/52317022
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;
const int inf = INT_MAX;
int n, m, k, ds;
int e[1020][1020], dis[1020];
bool visit[1020];
int main() {
    fill(e[0], e[0] + 1020 * 1020, inf);
    for (int i = 0; i < 1020; i++) e[i][i] = 0;
    scanf("%d%d%d%d", &n, &m, &k, &ds);
    string s, t;
    for (int i = 0; i < k; i++) {
        int tempdis;
        cin >> s >> t >> tempdis;
        int a, b;
        if (s[0] == 'G') {
            s = s.substr(1);
            a = n + stoi(s);
        } else {
            a = stoi(s);
        }
        if (t[0] == 'G') {
            t = t.substr(1);
            b = n + stoi(t);
        } else {
            b = stoi(t);
        }
        e[a][b] = e[b][a] = tempdis;
    }
    int ansid = -1;
    double ansdis = -1, ansaver = inf;
    for (int index = n + 1; index <= n + m; index++) {
        double mindis = inf, aver = 0;
        fill(dis, dis + 1020, inf);
        fill(visit, visit + 1020, false);
        dis[index] = 0;
        for (int i = 0; i < n + m; i++) {
            int u = -1, minn = inf;
            for (int j = 1; j <= n + m; j++) {
                if (visit[j] == false && dis[j] < minn) {
                    u = j;
                    minn = dis[j];
                }
            }
            if (u == -1) break;
            visit[u] = true;
            for (int v = 1; v <= n + m; v++) {
                if (visit[v] == false && e[u][v]!=inf && dis[v] > dis[u] + e[u][v])
                    dis[v] = dis[u] + e[u][v];
            }
        }
        for (int i = 1; i <= n; i++) {
            if (dis[i] > ds) {
                mindis = -1;
                break;
            }
            if (dis[i] < mindis) mindis = dis[i];
            aver += 1.0 * dis[i];
        }
        if (mindis == -1) continue;
        aver /= n ;
        if(mindis > ansdis || (mindis == ansdis && aver < ansaver)){
            ansdis = mindis;
            ansaver = aver;
            ansid = index;
        }
    }
    if (ansid == -1)
        printf("No Solution");
    else
        printf("G%d\n%.1f %.1f", ansid - n, ansdis, ansaver+0.001);
    return 0;
}