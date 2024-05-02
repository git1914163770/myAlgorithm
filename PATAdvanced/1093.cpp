#include<iostream>
#include<string>
using namespace std;

const int MAXN = 100001;
const int MOD = 1000000007;
int leftP[MAXN] = {0};
int main(){
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if(i > 0)
            leftP[i] = leftP[i-1];
        if(s[i] == 'P'){
            leftP[i]++;
        }
    }
    int rightT = 0;
    int res = 0;
    for(int i = s.size();i > 0 ;i--){
        if(s[i] == 'T'){
            rightT++;
        }else if(s[i] == 'A'){
            res = (res + leftP[i]*rightT) % MOD;
        }
    }
    cout << res;
    return 0;
}