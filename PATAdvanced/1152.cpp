#include<iostream>
#include<cmath>
#include<string>

using namespace std;

bool check(int sum){
    if(sum == 0 || sum == 1) return false;
    for(int i = 2;i*i<=sum;i++){
        if(sum % i == 0) return false;
    }
    return true;
}

// 自己想的，通过取模运算
// 乙1094
int main(){

    int L,K;
    cin >> L >> K;
    string s;
    cin >> s;
    int count = 0;
    int sum = 0;
    bool flag = false;
    int y = 1;
    // for(int i = 0;i<K-1;i++){
    //     y*=10;
    // }
    y = pow(10,K-1);
    for(int i = 0;i<s.size();i++){
        sum *= 10;
        sum += s[i] - '0';
        count++;
        if(count == K){
            if(check(sum)){
                for(int j = i-K+1;j<=i;j++){
                    cout << s[j];
                }
                // string t = "";
                // t+="%0";
                // t+=K+'0';
                // t+="d";
                // printf(t.c_str(),sum);
                return 0;
            }
            sum %= y;
            count--;
        }
    }
    cout << "404";
    return 0;
}

int func(){
    int l, k;
    string s;
    cin >> l >> k >> s;
    for (int i = 0; i <= l - k; i++) {
        string t = s.substr(i, k);
        int num = stoi(t);
        if (check(num)) {
            cout << t;
            return 0;
        }
    }
    cout << "404\n";
    return 0;
}