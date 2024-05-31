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
// https://blog.csdn.net/qq_43382350/article/details/129243773
// https://blog.csdn.net/qq_46107391/article/details/128976968
// https://blog.csdn.net/hzj913313180/article/details/130717200
#include<iostream>
#include<queue>
#include<climits>
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
            // 放在Q2中备用
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
    // func2();
    return 0;
}
// 自己想的，但超时
void func2(){
    int n,k;
    scanf("%d %d",&n,&k);
    int temp[n+1];
    int arr[k];
    for(int i = 0;i < n;i++){
        scanf("%d",&temp[i]);
    }
    for(int i = 0;i < k;i++){
        arr[i] = temp[i];
    }
    int index = k,minn,minidx = -1;
    int pre = INT_MIN;
    int f = 0;
    while(index < n+k){
        minn = INT_MAX;
        for(int i = 0;i < k;i++){
            // 题目说不小于 也即>=都放进去
            if(arr[i] < minn && arr[i] >= pre){
                minn = arr[i];
                minidx = i;
            }
        }
        if(minn == INT_MAX){
            pre = INT_MIN;
            printf("\n");
            f = 0;
            continue;
        }
        pre = minn;
        if(f) printf(" ");else f = 1;
        printf("%d",minn);
        if(index < n)
            arr[minidx] = temp[index];
        index++;
    }
}
