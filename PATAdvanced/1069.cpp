#include<cstdio>
#include<algorithm>
using namespace std;
bool cmp (int a,int b){
    return a > b;
}

void to_array(int n,int nums[]){
    // 如果不足4位，如个位数，需要补前导0
    for(int i = 0;i < 4;i++){
        nums[i] = n % 10;
        n = n / 10;
    }
}

int to_number(int num[]){
    int sum = 0;
    // int product = 1;
    // for(int i = 3;i>=0;i--){
    //     sum += num[i] * product;
    //     product *= 10;
    // }
    for(int i = 0;i < 4;i++){
        sum = sum * 10 + num[i];
    }
    return sum;
}

int main(){
    int n,MIN,MAX;
    scanf("%d",&n);
    int num[5];
    while(1){
        to_array(n,num);
        sort(num,num+4);
        MIN = to_number(num);
        sort(num,num+4,cmp);
        MAX = to_number(num);
        n = MAX - MIN;
        printf("%04d - %04d = %04d\n",MAX,MIN,n);
        if(n == 0 || n == 6174) break;
    }
    return 0;
}

// 其他方法 使用string 翻转 记得补0
// https://blog.csdn.net/qq_46527915/article/details/120918701
// https://blog.csdn.net/liuchuo/article/details/52497341
