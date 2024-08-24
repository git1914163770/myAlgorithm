#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m;
int nc[100001],np[100001];
bool cmp(int a,int b){ return a > b;}
int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&nc[i]);
    }
    scanf("%d",&m);
    for(int i = 0;i < m;i++){
        scanf("%d",&np[i]);
    }
    sort(nc,nc+n,cmp);
    sort(np,np+m,cmp);
    long long int res = 0;
    for(int i = 0,j = 0;i < n && j < m;){
        if(nc[i] > 0 && np[j] > 0){
            res += nc[i] * np[j];
            i++;
            j++;
        }else break;
    }
    for(int i = n - 1,j = m - 1;i >= 0 && j >= 0;){
        if(nc[i] < 0 && np[j] < 0){
            res += nc[i] * np[j];
            i--;
            j--;
        }else break;
    }
    printf("%ld",res);
    return 0;
}