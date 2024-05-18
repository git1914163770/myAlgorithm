#include<iostream>
#include<vector>
using namespace std;
//模拟找规律 乙1049
int main(){

    int n;
    cin >> n;
    long long sum = 0;
    double temp;
    // for (int i = 1; i <= n; i++) { 
    //     cin >> temp;
            
    //     sum += (long long)((temp * 1000) * i *(n - i + 1));
    // }

        // i及i前面的数量*i及i后面的数量
        //     举例1234
        //     对于2 12 123 1234 一组3个
        //     2 23 234 一组3个 共6个
    // printf("%.2f", sum / 1000.0);

    for(int i = 0;i<n;i++){
        cin >> temp;
        sum += (long long)(temp*1000*(i+1)*(n-i));

        // 或者使用long double 定义temp sum
        // 输入 scanf("%llf",&temp);
        // 输出 printf("%.2llf\n",sum);
    }
    printf("%.2f", sum / 1000.0);
    return 0;
}

