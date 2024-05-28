// 示例图是从下往上数，不过不影响
// 共享同一个x+y y-x 三个set 因为 y = x + b y = -x + b 
// 或者(y2-y1)/(x2-x1)

#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int arr[1001];
int N;

bool check(){
    set<int> m,d1,d2;
    for(int i = 0;i < N;i++){
        if(m.count(arr[i]) || d1.count(i+arr[i]) || d2.count(arr[i]-i)) return false;
        m.insert(arr[i]);
        d1.insert(i+arr[i]);
        d2.insert(arr[i]-i);
    }
    return true;    
}

int main(){
    int k;
    scanf("%d",&k);
    while(k--){
        scanf("%d",&N);
        for(int i = 0;i < N;i++){
            scanf("%d",&arr[i]);
        }
        if(check())printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}