#include<iostream>
#include<algorithm>
#include<vector>
typedef long long int LL;

using namespace std;

// 双指针
void func2(){
    int a[200001],b[200001],c[400001];
    int n,m,d;
    cin >> n;
    for(int i = 0;i < n;i++){
        // long int和int 一样大,不需要long long int
        scanf("%d",&a[i]);
    }
    cin >> m;
    for(int i = 0;i < m;i++){
        scanf("%d",&b[i]);
    }
    int i,j,cnt;
    for(i = 0,j = 0,cnt = 0;i < n && j < m;){
        if(a[i]<b[j]) c[cnt++] = a[i++];
        else c[cnt++] = b[j++];
    }
    while(i < n) c[cnt++] = a[i++];
    while(j < m) c[cnt++] = b[j++];
    printf("%d",c[(m+n-1)/2]);
}

// 直接排序
int main(){
    vector<LL> vec;
    int n,m;
    cin >> n;
    LL d;
    for(int i = 0;i < n;i++){
        scanf("%lld",&d);
        vec.push_back(d);
    }
    cin >> m;
    for(int i = 0;i < m;i++){
        scanf("%lld",&d);
        vec.push_back(d);
    }
    sort(vec.begin(),vec.end());
    printf("%lld",vec[(vec.size()-1)/2]);
    // func2();
    return 0;
}

