#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_map>

// 乙1090
using namespace std;

int main(){
    unordered_map<int,vector<int>> m;
    int n,M;
    cin >> n >> M;
    for(int i = 0;i<n;i++){
        int a ,b;
        scanf("%d %d",&a,&b);
        m[a].push_back(b);
        // m[b].push_back(a);
    }
    for(int i = 0;i<M;i++){
        int a;cin >> a;
        unordered_map<int,int> hush;
        vector<int> v(a);
        for(int i = 0;i<a;i++){
            scanf("%d",&v[i]);
            hush[v[i]] = 1;
        }
        bool flag = 0;
        // 判断任一货物的不兼容货物是否在这堆货物中
        // for(int i = 0;i<a;i++){
        //     for(int j = 0;j<m[v[i]].size();j++){
        //         if(hush[m[v[i]][j]] == 1){
        //             flag = 1;
        //             break;
        //         }
        //     }
        //     if(flag != 0) break;
        // }
        for(auto i:v){
            for(auto child:m[i]){
                if(hush[child] == 1){
                    flag = 1;
                    break;
                }
            }
            if(flag != 0) break;
        }
        printf("%s\n",flag ? "No" :"Yes");
    }
    return 0;
}