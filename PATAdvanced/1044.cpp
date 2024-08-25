#include<iostream>
#include<cstdio>
#include<climits>
#include<vector>
using namespace std;

int n,m;
int c[100001],s[100001];
int mindis = INT_MAX;
vector<pair<int,int>> res;
int main(){
    scanf("%d %d",&n,&m);
    for(int i = 1;i <= n;i++){
        scanf("%d",&c[i]);
        s[i] = s[i - 1] + c[i];
    }
    for(int l = 1,r = 1;r <= n;){
        if(s[r] - s[l - 1] < m)
            r++;
        else{
            if(s[r] - s[l - 1] < mindis){
                mindis = s[r] - s[l - 1];
                res.clear();
                res.push_back({l,r});
            }else if(s[r] - s[l - 1] == mindis){
                res.push_back({l,r});
            }
            l++;
        }
    }
    for(auto i = res.begin();i != res.end();i++)
        printf("%d-%d\n",i->first,i->second);
    // for (int i = 0; i < res.size(); ++i) {
    //     printf("%d-%d\n",res[i].first,res[i].second);
    // }
    return 0;
}