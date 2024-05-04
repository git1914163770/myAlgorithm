#include<iostream>
#include<map>
#include<set>
#include<string>
#include<cstdio>
using namespace std;

map<string,set<int>> stu;
int n,k;
int main(){
    scanf("%d %d",&n,&k);
    int id,nums;
    char temp[5];
    for(int i = 0;i < k;i++){
        scanf("%d %d\n",&id,&nums);
        for(int j = 0;j < nums;j++){
            scanf("%s",temp);
            stu[temp].insert(id);
        }
    }
    for(int i = 0;i < n;i++){
        // cin >> temp;
        scanf("%s",temp);
        printf("%s",temp);
        // cout << temp;
        printf(" %d",stu[temp].size());
        for(auto it = stu[temp].begin();it != stu[temp].end();it++){
            printf(" %d",*it);
        }
        printf("\n");
    }
    return 0;
}