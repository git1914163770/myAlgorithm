#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    string s = to_string(a+b);
    if(s[0] == '-'){
        cout << '-';
        s = s.substr(1);
    }
    reverse(s.begin(),s.end());
    for(int i = s.size()-1;i>=0;i--){
        cout << s[i];
        if(i && i % 3 == 0) cout << ',';
    }

    return 0;
}