#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
vector<int> v[100010];
double p, r;
int mindepth = 100010,num;

// 甲1079 1090 1106
void dfs(int index, int depth) {
    if(v[index].size() == 0) {
        if(depth < mindepth){
            mindepth = depth;
            num = 1;
        }else if(depth == mindepth){
            num ++;
        }
        return ;
    }
    for(int i = 0; i < v[index].size(); i++)
        dfs(v[index][i], depth + 1);
}
int main() {
    int n, k, c;
    scanf("%d %lf %lf", &n, &p, &r);
    r = r / 100;
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        if(k != 0) {
            for(int j = 0; j < k; j++) {
                scanf("%d", &c);
                v[i].push_back(c);
            }
        }
    }
    dfs(0, 0);
    // 数量* 价格 ，或者将*p放到dfs里
    printf("%.4lf %d", p * pow(1 + r,mindepth),num);
    return 0;
}