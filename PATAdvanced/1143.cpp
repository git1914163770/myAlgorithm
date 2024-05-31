#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<int,bool> mp;
// https://blog.csdn.net/liuchuo/article/details/79618849
// https://programmercarl.com/0235.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.html#%E6%80%9D%E8%B7%AF
int main(){
    int m,n,u,v,a;
    scanf("%d %d",&m,&n);
    vector<int> pre(n);
    for(int i = 0;i < n;i++){
        scanf("%d",&pre[i]);
        mp[pre[i]] = true;
    }
    for(int i = 0;i < m;i++){
        scanf("%d %d",&u,&v);
        for(int j = 0;j < n;j++){
            a = pre[j];
            if((a > u && a < v) || (a > v && a < u) || (a == u) || (a == v))break;
            // if(!((a > u && a > v) || (a < u && a < v))) break;
        }
        
        if (mp[u] == false && mp[v] == false)
            printf("ERROR: %d and %d are not found.\n", u, v);
        else if (mp[u] == false || mp[v] == false)
            printf("ERROR: %d is not found.\n", mp[u] == false ? u : v);
        else if (a == u || a == v)
            printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
        else
            printf("LCA of %d and %d is %d.\n", u, v, a);
    }
    return 0;
}