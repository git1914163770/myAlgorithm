// https://blog.csdn.net/qq_46527915
// 先初始化都是坏的，然后如有一段相同的字符串长度不可以整除k，那么就是好的
#include<iostream>
#include<map>
#include<string>
using namespace std;
int k;
string s;
map<char,int> st,hush;
int main(){
    for(int i = 0;i < 10;i++) st['0' + i] = -1;
    for(int i = 0;i < 26;i++) st['a' + i] = -1;
    st['_'] = -1;
    cin >> k >> s;
    for(int i = 0;i < s.size();i++){
        int j = i;
        while(j+1 < s.size() && s[i] == s[j+1]) j++;
        if((j - i + 1) % k != 0) st[s[i]] = 0;
        i = j;
    }
    for(int i = 0;i < s.size();i++){
        if(st[s[i]] == -1 && !hush[s[i]]) cout<<s[i],hush[s[i]]++;
    }
    cout << endl;
    for(int i = 0;i < s.size();){
        cout << s[i];
        if(st[s[i]] == -1){
            int j = i + k;
            i = j;
        }else i++;
    }
    return 0;
}