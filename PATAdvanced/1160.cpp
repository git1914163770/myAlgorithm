#include<bits/stdc++.h>
using namespace std;
// https://blog.csdn.net/hzj913313180/article/details/130716927
// 乙1104
int k, m, t;
// 判断一个数是否是质数
bool isPrime(int x){
    if(x <= 2) return false;
    for(int i = 2; i <= x / i; i ++) {
        if(x % i == 0) return false;
    }
    return true; 
}

// DFS函数，用于枚举符合条件的数字
void dfs(int cnt, int sum, int x, set<pair<int, int>> &ans){
    // 剪枝条件：数位超过k，各位数字之和超过m，或者各位数字之和无法通过后面的数字补充达到m
    if(cnt > k || sum > m || m > sum + 9*(k-cnt)) return;

    // 找到一个符合条件的数字
    if(cnt == k && sum == m){
        int y = x + 1, n = 0;
        while(y){
            n += y%10;
            y /= 10;
        } 
        // 检查最大公约数是否大于2，如果是则加入结果集
        if(isPrime(__gcd(n, m))) ans.insert({n, x});
        return;        
    }

    // 枚举下一位数字
    for(int i = 0; i <= 9; i ++){
        if(sum == 0 && i == 0) continue; // 去掉首位为0
        else if(cnt >= k-2){
            // 最后两位必须是9，减少不必要的计算
            dfs(cnt+1, sum+9, x*10+9, ans);
            break;
        } else {
            dfs(cnt + 1, sum + i, x*10 + i, ans);
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int i = 1 ; i <= t ; i ++ ){
        printf("Case %d\n", i);
        set<pair<int, int>> ans;
        scanf("%d %d", &k, &m);
        dfs(0, 0, 0, ans);
        if(!ans.size()) printf("No Solution\n");
        for(auto j : ans) printf("%d %d\n", j.first, j.second);
    }
    return 0;
}
