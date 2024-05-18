#include <iostream>
#include <unordered_set>
#include <climits>
using namespace std;
int n;
int set[100010];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x > 0 && x <= 100000) set[x] = 1;
    }
    for (int i = 1; i <= 100001; ++i) {
        if (set[i] == 0) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

int func2(){
    unordered_set<int> set;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        set.insert(x);
    }
    for (int i = 1; i < INT_MAX; ++i) {
        if (!set.count(i)) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}