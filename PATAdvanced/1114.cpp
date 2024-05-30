#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

struct DATA{
    int id,fid,mid,setnum,area;
    vector<int> child;
}d[10001];

int parent[10001];

struct node{
    int id,peoplenum;
    double setnum;
    double avgarea;
    bool flag = false;
}countarr[10001];
// 平均面积降序 ID升序
int cmp(node a,node b){
    if(a.avgarea != b.avgarea){
        return a.avgarea > b.avgarea;
    }else return a.id < b.id;
}
// 因为id 不连续，使用set/数组 保存每个出现的id
bool visit[10000];

int find(int x){
    if(parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}

void Union(int a,int b){
    int fA = find(a);
    int fB = find(b);
    if(fA < fB){
        parent[fB] = fA;
    }else if(fB < fA){
        parent[fA] = fB;
    }
}


int main(){
    int n,k;
    scanf("%d",&n);
    // 别忘了初始化parent
    for(int i = 0;i < 10000;i++)
        parent[i] = i;
    int child;
    for(int i = 0;i < n;i++){
        int tempid;
        scanf("%d",&tempid);
        scanf("%d %d %d",&d[tempid].fid,&d[tempid].mid,&k);
        visit[tempid] = true;
        if(d[tempid].fid != -1){
            Union(tempid,d[tempid].fid);
            visit[d[tempid].fid] = true;
        }
        if(d[tempid].mid != -1){
            Union(tempid,d[tempid].mid);
            visit[d[tempid].mid] = true;
        }
        for(int j = 0;j < k;j++){
            scanf("%d",&child);
            visit[child] = true;
            Union(tempid,child);
        }
        scanf("%d %d",&d[tempid].setnum,&d[tempid].area);
    }
    int cnt = 0;
    // 注意这里不能是0-n ，应要对每个人计算
    for(int i = 0;i < 10000;i++){
        if(visit[i]){
            int id = find(i);
            countarr[id].id = id;
            countarr[id].setnum += d[i].setnum;
            countarr[id].avgarea += d[i].area;
            countarr[id].flag = true;
            countarr[id].peoplenum++;
        }
    }
    for(int i = 0;i < 10000;i++){
        // 注意要上面完整求出人数后才能计算平均值，所以两个for循环不能合在一起
        if(countarr[i].flag){
            cnt++;
            countarr[i].setnum = countarr[i].setnum * 1.0 / countarr[i].peoplenum;
            countarr[i].avgarea = countarr[i].avgarea * 1.0 / countarr[i].peoplenum;
        }
    }
    sort(countarr,countarr + 10000,cmp);
    printf("%d\n",cnt);
    for(int i = 0;i < cnt;i++){
        printf("%04d %d %.3f %.3f\n",countarr[i].id,countarr[i].peoplenum,countarr[i].setnum,countarr[i].avgarea);
    }
    return 0;
}