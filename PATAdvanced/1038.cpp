#include <iostream>
#include <string>
#include <algorithm>
// https://blog.csdn.net/liuchuo/article/details/52264827
using namespace std;
bool cmp0(string a, string b) {
    return a + b < b + a;
}
string str[10010];
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        cin >> str[i];
    sort(str, str + n, cmp0);
    string s;
    for(int i = 0; i < n; i++)
        s += str[i];
    while(s.length() > 1 && s[0] == '0')
        s.erase(s.begin());
        // 或者s=s.substr(1);
    cout << s;
    return 0;
}