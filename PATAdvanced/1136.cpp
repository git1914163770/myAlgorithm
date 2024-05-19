#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

bool check(string s){
    for(int i = 0,j = s.size()-1;i<j;i++,j--){
        if(s[i] != s[j]) return false;
    }
    return true;
}

// 自己想的，本题不需要去除前导0
// 如果刚开始就是回文数，直接输出，所以刚开始要check
int main(){
    string s1;
    cin >> s1;
    string s2 = s1;
    int cnt = 0;
    if(check(s1)){
        cout << s1 << " is a palindromic number.";
        return 0;
    }
    while(1){
        reverse(s1.begin(),s1.end());
        int t = 0;
        string temp = "";
        for(int i = s2.size()-1;i>=0;i--){
            t += (s2[i]-'0') + (s1[i]-'0');
            temp += t % 10 + '0';
            t /= 10;
        }
        if(t != 0) temp+=(t + '0');
        reverse(temp.begin(),temp.end());
        cout << s2 << " + " << s1 << " = " << temp<<endl; 
        if(check(temp)){
            cout << temp << " is a palindromic number.";
            break;
        }
        s2 = temp; s1 = temp;
        cnt ++;
        if(cnt == 10){
            cout << "Not found in 10 iterations.";
            break;
        }

    }
    return 0;
}
// 乙1079
// https://blog.csdn.net/liuchuo/article/details/79064855
