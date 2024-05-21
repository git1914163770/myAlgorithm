// https://blog.csdn.net/liuchuo/article/details/134353343
// 乙1115

#include<iostream>
#include<unordered_map>
#include<vector>
#include<cmath>
using namespace std;

int chuju[11];

int main(){

    // unordered_map<int,int> cha;
    vector<int> used(2);
    // 比unordered_map 快
    // 100000+100000 = 200000
    int smap[200005] = {0};
    int n1,n2;
    cin >> n1 >> n2;
    smap[n1] = 1;smap[n2] = 1;
    used[0] = n1;used[1] = n2;
    
    // cha[abs(n1-n2)] = 1; 
    int a,b;
    cin >> a >> b;
    int arr[a][b];
    for(int i = 0;i<a;i++){
        for(int j = 0;j<b;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int j = 0;j<b;j++){
        for(int i = 0;i<a;i++){
            if(chuju[i]) continue;
            int f = 0;
            if(smap[arr[i][j]] == 1){
                chuju[i] = 1;
                printf("Round #%d: %d is out.\n",j+1,i+1);
                continue;
            }
            // 判断已有数字与当前数字之和是否存在，若存在，添加当前当前数字，并break;
            for(auto it : used){
                if(smap[it + arr[i][j]] == 1){
                    smap[arr[i][j]] = 1;
                    f = 1;
                    used.push_back(arr[i][j]);
                    break;
                }
            }
            if(f == 0){
                chuju[i] = 1;
                printf("Round #%d: %d is out.\n",j+1,i+1);
            }
            // 超时做法，计算每个差值并统计
            // if(smap[arr[i][j]] != 1 && cha[arr[i][j]] == 1){
            //     smap[arr[i][j]] = 1;
            //     for(auto it = smap.begin();it!=smap.end();it++){
            //         cha[abs(arr[i][j] - it->first)] = 1;
            //     }
            // }else{
            //     printf("Round #%d: %d is out.\n",j+1,i+1);
            //     chuju[i] = 1;
            // }
        }
    }
    string s = "Winner(s):";
    int flag = 0;
    for(int i = 0;i<a;i++){
        if(chuju[i] == 0){
            flag = 1;
            s+=" "+to_string(i+1);
        }
    }
    if(flag)
        cout << s;
    else {
        cout << "No winner.";
    }
    return 0;
}