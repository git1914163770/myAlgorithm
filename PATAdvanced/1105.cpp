#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
// 乙 1050
int cmp(int a,int b){return a > b;}
int main(){
    int N,m,n;
    scanf("%d",&N);
    // for(n = sqrt((double)N);n >= 1;n--){
    //     if (N % n == 0){
    //         m = N / n;
    //         break;
    //     }
    // }
    // 或者
    for(int i = 1;i <= sqrt(N);i++){
        if(N % i == 0){
            m = i;
            n = N / i;
        }
    }
    if(m < n) swap(m,n);
    int a[N];
    for(int i = 0;i<N;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+N,cmp);
    int b[m][n];
    int top,bottom,left,right;
    top = 0,bottom = m - 1,left = 0,right = n - 1;
    int count = 0;
    int sum = N;
    while(count < sum){
        int i = top;
        int j = left;
        while(j<=right && count < sum){
            b[i][j] = a[count++];
            j++;
        }
        i = top+1;
        j = right;
        while(i<=bottom && count < sum){
            b[i][j] = a[count++];
            i++;
        }
        i = bottom;
        j = right - 1;
        while(j>=left && count < sum){
            b[i][j] = a[count++];
            j--;
        }
        i = bottom - 1;
        j = left;
        while(i > top && count < sum){
            b[i][j] = a[count++];
            i--;
        }
        top = top+1,left = left+1,bottom = bottom-1,right = right - 1;
    }
    for(int i = 0;i<m;i++){
        for(int j = 0;j < n;j++){
            if(j != 0) printf(" ");
            printf("%d",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}