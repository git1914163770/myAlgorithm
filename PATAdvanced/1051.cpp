#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int main(){
    int m,n,k;
    scanf("%d %d %d",&m,&n,&k);
    for(int i = 0;i < k;i++){
        stack<int> s;
        vector<int> v(n + 1);
        for(int j = 1;j <= n;j++)
            scanf("%d",&v[j]);
        int index = 1;
        for(int j = 1;j <= n;j++){
            s.push(j);
            if(s.size() > m) break;
            while(!s.empty() && s.top() == v[index]){
                s.pop();
                index++;
            }
        }
        // 或者if(s.empty())
        if(index == n + 1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}