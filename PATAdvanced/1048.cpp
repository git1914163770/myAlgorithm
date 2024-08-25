#include <iostream>
using namespace std;
int a[1001];
int main() {
    int n, m, temp;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        a[temp]++;
    }
    for(int i = 0; i <= m / 2; i++) {
        if(a[i] && a[m - i]) {
            // 对 m = 14 数组只有一个7特殊处理
            if(i == m - i && a[i] < 2) continue;
            printf("%d %d", i, m - i);
            return 0;
        }
    }
    printf("No Solution");
    return 0;
}