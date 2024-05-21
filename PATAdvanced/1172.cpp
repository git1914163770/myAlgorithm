#include<iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[10001] = {0};
    int left[10001] = {0};
    int right[10001] = {0};
    for(int i = 1;i<=n;i++){
        cin >> arr[i];
    }
    // 自己想的，如果当前数大于右边，就将left[i] = left[i+1] + 1
    // 就不用on^2的双重for了
    for(int i = n-1;i>=1;i--){
        if(arr[i] > arr[i+1]){
            left[i] = left[i+1] + 1;
        }else if(arr[i] == arr[i+1]){
            left[i] = left[i+1];
        }else{
            left[i] = 0;
        }
    }
    // for(int i = 1;i<n;i++){
    //     int j = i;
    //     while(j + 1 <= n && arr[j] >= arr[j+1]){
    //         if(arr[j] > arr[j +1]) ++left[i];
    //         ++j;
    //     }
    // }
    for(int i = n;i>1;i--){
        int j = i;
        while(j - 1 >= 1 && arr[j]>=arr[j-1]){
            if(arr[j] > arr[j-1])right[i]++;
            --j;
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++) ans += max(left[i],right[i]) * 100 + 200;
    cout << ans;
    return 0;
}