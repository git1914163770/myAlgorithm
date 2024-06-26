#include <cstdio>
#include <set>
using namespace std;
int book[50001];
//https://blog.csdn.net/liuchuo/article/details/68912867
//https://huixiaoge.blog.csdn.net/article/details/121525755
struct node {
    int value, cnt;
    node(int a, int b):value(a), cnt(b){}
    bool operator < (const node &a) const {
        return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
    }
};
int main() {
    int n, k, num;
    scanf("%d%d", &n, &k);
    set<node> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (i != 0) {
            printf("%d:", num);
            int tempCnt = 0;
            for(auto it = s.begin(); tempCnt < k && it != s.end(); it++) {
                printf(" %d", it->value);
                tempCnt++;
            }
            printf("\n");
        }
        auto it = s.find(node(num, book[num]));
        if (it != s.end()) s.erase(it);
        book[num]++;
        s.insert(node(num, book[num]));
    }
    return 0;
}