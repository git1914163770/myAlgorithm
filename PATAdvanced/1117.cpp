// 从大到小排序，如果第k天大于k，则1-k天一定也大于k
// 乙1060
#include <iostream>
#include <algorithm>

using namespace std;
const int N = 100010;
int day[N];
int n;

int main() {
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> day[i];
    }
    sort(day + 1, day + n + 1, greater<int>());
    for (int i = n; i >= 1; i--) {
        if (day[i] > i) {
            cout << i;
            return 0;
        }
    }
    puts("0");
    return 0;
}
