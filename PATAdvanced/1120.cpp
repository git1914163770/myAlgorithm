#include<iostream>
#include<string>
#include<set>
//乙1064
using namespace std;
int n;
set<int> s;
int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        string number;
        cin >> number;
        int sum = 0;
        for(auto &c:number){
            sum += c - '0';
        }
        s.insert(sum);
    }
    cout << s.size() << endl;
    bool flag = true;
    for(auto &x:s){
        if(flag) flag = false;
        else printf(" ");
        printf("%d",x);
    }
    // 另一种遍历方式
    // for(auto it = s.begin(); it != s.end(); it++) {
    //     if(it != s.begin()) printf(" ");
    //     printf("%d", *it);
    // }
    return 0;
}