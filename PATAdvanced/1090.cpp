#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n,maxdepth = 0,maxnum = 0;
vector<int> v[100010];

void dfs(int index,int depth){
    if(v[index].size() == 0){
        if(depth > maxdepth){
            maxdepth = depth;
            maxnum = 1;
        }else if(depth == maxdepth){
            maxnum++;
        }
        return;
    }
    for(int i = 0;i < v[index].size();i++){
        dfs(v[index][i],depth+1);
    }
}

int main(){
    double p,r;
    scanf("%d %lf %lf",&n,&p,&r);
    int temp,root;
    for(int i = 0;i < n;i++){
        scanf("%d",&temp);
        if(temp == -1){
            root = i;
        }else{
            v[temp].push_back(i);
        }
    }
    dfs(root,0);
    printf("%.2f %d",p * pow(1 + r / 100 ,maxdepth),maxnum);
    return 0;
}