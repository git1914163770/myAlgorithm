#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
// char name[40010][5];
vector<string> course[2510];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char name[5];
    for(int i = 0; i < n; i++) {
        int cnt, temp;
        scanf("%s %d", name, &cnt);
        for(int j = 0; j < cnt; j++) {
            scanf("%d", &temp);
            course[temp].push_back(name);
        }
    }
    for(int i = 1; i <= k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end());
        for(int j = 0; j < course[i].size(); j++)
            printf("%s\n", course[i][j].c_str());
    }
    return 0;
}