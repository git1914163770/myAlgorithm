#include <cstdio>
#include <algorithm>
using namespace std;
struct DATA {
    int id, fid, mid, num, area;
    int cid[10];
}d[1005];   
struct node {
    // people 家庭成员数
    int id, people;
    // num 房产数
    double num, area;
    // 换成vector 就不需要flag
    bool flag = false;
}ans[10000];
int father[10000];

bool visit[10000];
int find(int x) {
    // while(x != father[x])
    //     x = father[x];
    // return x;
    if(father[x] != x) father[x] = find(father[x]);
    return father[x];   
}
void Union(int a, int b) {
    int faA = find(a);
    int faB = find(b);
    if(faA > faB)
        father[faA] = faB;
    else if(faA < faB)
        father[faB] = faA;
}
// 平均面积降序 ID升序
int cmp1(node a, node b) {
    if(a.area != b.area)
        return a.area > b.area;
    else
        return a.id < b.id;
}
int main() {
    int n, k, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < 10000; i++)
        father[i] = i;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &d[i].id, &d[i].fid, &d[i].mid, &k);
        visit[d[i].id] = true;
        if(d[i].fid != -1) {
            visit[d[i].fid] = true;
            Union(d[i].fid, d[i].id);
        }
        if(d[i].mid != -1) {
            visit[d[i].mid] = true;
            Union(d[i].mid, d[i].id);
        }
        for(int j = 0; j < k; j++) {
            scanf("%d", &d[i].cid[j]);
            visit[d[i].cid[j]] = true;
            Union(d[i].cid[j], d[i].id);
        }
        scanf("%d %d", &d[i].num, &d[i].area);
    }
    for(int i = 0; i < n; i++) {
        int id = find(d[i].id);
        ans[id].id = id;
        ans[id].num += d[i].num;
        ans[id].area += d[i].area;
        ans[id].flag = true;
    }
    for(int i = 0; i < 10000; i++) {
        // 因为是用数组存的。用vector/map存就不需要visit数组
        if(visit[i])
            ans[find(i)].people++;

        if(ans[i].flag)
            cnt++;
    }
    for(int i = 0; i < 10000; i++) {
        if(ans[i].flag) {
            ans[i].num = (double)(ans[i].num * 1.0 / ans[i].people);
            ans[i].area = (double)(ans[i].area * 1.0 / ans[i].people);
        }
    }
    sort(ans, ans + 10000, cmp1);
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++)
        printf("%04d %d %.3f %.3f\n", ans[i].id, ans[i].people, ans[i].num, ans[i].area);
    return 0;
}