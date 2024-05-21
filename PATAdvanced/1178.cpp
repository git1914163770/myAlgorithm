#include<iostream>
#include<string>
#include<map>
using namespace std;
int N,K;
string s,root,ans;
map<string,string> superior;
map<int,string> last;
int main(){
    cin >> N >> root;
    last[0] = root;
    superior[root] = root;
    getchar();
    int index;
    // 要保存上一级的父节点，自底向上遍历（类似并查集遍历）
    for(int i = 1;i < N;i++){
        getline(cin,s);
        index = 0;
        while(s[index] == ' ')++index;
        superior[s.substr(index)] = last[index - 1];
        last[index] = s.substr(index);
    }
    scanf("%d",&K);
    while (K--) {
        cin >> s;
        if (!superior.count(s)) cout << "Error: " << s << " is not found.\n";
        else {
            ans = "\n";
            while (s != root) {
                ans = "->" + s + ans;
                s = superior[s];
            }
            cout << root << ans;
        }
    }
    return 0;
}