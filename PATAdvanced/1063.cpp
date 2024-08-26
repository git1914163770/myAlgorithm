#include<iostream>
#include<cstdio>
#include<unordered_set>
#include<vector>

using namespace std;

int main(){
    int n,m,k;
    int temp;
    scanf("%d",&n);
    vector<unordered_set<int>> v(n);
    for(int i = 0;i < n;i++){
        unordered_set<int> s;
        scanf("%d",&m);
        for(int j = 0;j < m;j++){
            scanf("%d",&temp);
            s.insert(temp);
        }
        v[i] = s;
    }
    scanf("%d",&k);
    int a,b;
    for(int i = 0;i < k;i++){
        scanf("%d %d",&a,&b);
        int nc = 0,nt = v[b - 1].size();
        for(auto it :v[a-1]){
            if(v[b - 1].find(it) != v[b - 1].end()){
                nc++;
            }else{
                nt++;
            }
        }
        double ans = 1.0 * nc / nt * 100;
        printf("%.1f%\n",ans);            
    }
    return 0;
}