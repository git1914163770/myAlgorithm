#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    bool flag = true;
    int leftindex = 0, rightindex = n - 1, sum = INT32_MIN, temp = 0, tempindex = 0;
    for(int i = 0;i < n;i++){
        scanf("%d", &v[i]);
        if(v[i] >= 0) flag = false; 
    }
    if(flag){
        printf("0 %d %d", v[0], v[n-1]);
        return 0;
    }
    for (int i = 0; i < n; i++) {
        temp = temp + v[i];
        if (temp > sum) {
            sum = temp;
            leftindex = tempindex;
            rightindex = i;
        }
        if (temp < 0) {
            temp = 0;
            // 在<0和>0的交界处作为左端点
            tempindex = i + 1;
        }
    }
    printf("%d %d %d", sum, v[leftindex], v[rightindex]);
    return 0;
}