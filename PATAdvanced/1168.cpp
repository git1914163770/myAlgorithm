#include<iostream>
#include<string>
#include<cmath>
using namespace std;

bool isprime(int a){
    if(a<2) return false;
    for(int i = 2;i<=sqrt(a);i++){
        if(a % i == 0) return false;
    }
    return true;
}

// 乙1114
int main(){
    string s;
    cin >> s;
    int flag = 0;
    int temp;
    for(int i = 0;i<s.size();i++){
        string t = s.substr(i);
        temp = stoi(t);
        if(isprime(temp)){
            cout << t << " Yes"<<endl;
        }else{
            cout << t << " No" << endl;
            flag = 1;
        }
    }
    if(!flag) cout << "All Prime!";
    return 0;
}