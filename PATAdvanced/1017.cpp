// 每次选耗时最短的入队，等待时间=服务时间-进入时间
// 16 60 
// 15 2 10 
// 30 
// 进入时间小于五点，服务时间超过五点的是否要服务？需要服务

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int maxn = 10005;
struct person {
    int come, time;
} p[maxn];
int cmp(person p1, person p2) { return p1.come < p2.come; }

int main(){
    int n,k;
    cin >> n >> k;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        int hh,mm,ss,tt;
        scanf("%d:%d:%d %d",&hh,&mm,&ss,&tt);
        int sum = hh * 3600 + mm * 60 + ss;
        // 61200 = 17*60*60;
        if (sum > 61200) continue;
        // 不知道为什么去掉下面这个注释也能过
        // if (tt > 60) tt = 60;
        
        p[cnt].come = sum;
        p[cnt].time = tt*60;
        cnt++;
    }
    sort(p, p + cnt, cmp);
    int bank[k];
    // 28800 = 8*60*60;
    fill(bank,bank+k,28800);

    int sum = 0;
    for(int i = 0;i<cnt;i++){
        int minn = 0;
        for(int j = 1;j<k;j++){
            if(bank[j] < bank[minn]) minn = j;
        }
        // 上一个结束时间<=进入时间
        if(bank[minn]<=p[i].come){
            bank[minn] = p[i].time+p[i].come;
        }else{
            sum += bank[minn] - p[i].come;
            // cout << sum <<endl;
            bank[minn] += p[i].time;
            // cout << p[i].time << " "  << bank[minn]<<endl;
        }
    }
    //没有服务的情况
    if(!cnt) printf("0.0\n");
    else printf("%.1lf",((double)sum/60.0)/(double) cnt);
    return 0;
}

// 使用堆排序，其他逻辑相同
int func2() {
    int n, k, cnt, total;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int hh, ss, mm, tt;
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &tt);
        int sum = hh * 3600 + mm * 60 + ss;
        if (sum > 61200) continue;
        p[++cnt].time = tt * 60;
        p[cnt].come = sum;
    }
    sort(p + 1, p + 1 + cnt, cmp);
    // 算法笔记P223 小根堆
    priority_queue<int, vector<int>, greater<int> > q;
    for (int i = 1; i <= k; ++i) q.push(28800);
    for (int i = 1; i <= cnt; ++i) {
        if (q.top() <= p[i].come) {
            q.push(p[i].come + p[i].time);
            q.pop();
        } else {
            total += q.top() - p[i].come;
            q.push(q.top() + p[i].time);
            q.pop();
        }
    }
    (!cnt) ? printf("0.0\n") : printf("%.1lf", ((double)total/60.0)/(double) cnt);
    return 0;
}