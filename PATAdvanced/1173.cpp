#include<iostream>

using namespace std;

int main(){
    int n,num;
    cin >> n >> num;
    int v[n];
    for(int i = 0;i< n;i++){
        cin >> v[i];
    }
    int count =0;
    int sum = 0;
    for(int i = 0;i < n;i++){
        sum = 0;
        for(int j = i;j<n;j++){
            sum += v[j];
            if(sum > num){
                break;
            }
            count ++;
        }
    }
    cout << count ;
    return 0;
}
// int N, M, ans, a, pre[10005];
// int main(){
//     cin >> N >> M;
//     for (int i = 1; i <= N; i++) {
//         cin >> a;
//         pre[i] = pre[i - 1] + a;
//     }
//     for (int i = 1; i <= N; i++) {
//         for (int j = i; j <= N; j++) {
//             if (pre[j] - pre[i - 1] <= M) ++ans;
//             else break;
//         }
//     }
//     cout << ans;
//     return 0;
// }