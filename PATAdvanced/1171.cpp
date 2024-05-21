// 81 94 11
// 96 12 99
// 17 35 28
// 58 41 75
// 15

// 11 81 94 96 12(2) 99 17(2) 35(2) 28(2) 58(2) 41(2) 75(2) 15(3)
// 11 81 94 96 99
// 12 17 28 35 41 58 75
// 15
// https://www.bilibili.com/video/BV1b7411N798?p=98&vd_source=5ade3cf0f543475963e7d592cc8e27d0
// https://blog.csdn.net/liuchuo/article/details/134354244

#include<iostream>
#include<queue>
using namespace std;
// index 当前正在处理的下标 now 从优先队列中取出的最小值
// A 输入数据
int n,m,A[100005],index,now;
priority_queue<int,vector<int>,greater<int>> Q1,Q2;
int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        scanf("%d",&A[i]);
        if(i <= m) Q1.push(A[i]);
    }
    index = m + 1;
    while(Q1.size()){
        now = Q1.top();
        printf("%d",now);
        Q1.pop();
        if(index <= n){
            if(A[index] < now) Q2.push(A[index]);
            else Q1.push(A[index]);
            index++;
        }
        if(Q1.size()) printf(" ");
        else{
            swap(Q1,Q2);
            printf("\n");
        }
    }
    return 0;
}