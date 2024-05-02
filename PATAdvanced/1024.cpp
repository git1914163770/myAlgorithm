#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isPalindromic(vector<int> &vec){
    for(int i = 0,j = vec.size() - 1;i < j;i++,j--){
        if(vec[i] != vec[j]) return false;
    }
    return true;
}

// 输出低位对应数组低位
vector<int> addNumber(vector<int> &vec){
    vector<int> b;
    vector<int> res;
    for(int i = vec.size() - 1;i >= 0;i--){
        b.push_back(vec[i]);
    }
    int carry = 0;
    for(int i = 0;i < vec.size() || i < b.size();i++){
        int t = vec[i] + b[i] + carry;
        res.push_back(t % 10);
        carry = t / 10;
    }
    if(carry){
        res.push_back(carry);
    }
    return res;
}

int main(){
    string s;
    int k;
    cin >> s >> k;
    vector<int> vec;
    for(int i = s.size()-1;i >= 0;i--){
        vec.push_back(s[i] - '0');
    }
    int cnt = 0;
    while(k--){
        if(isPalindromic(vec)){
            for(int i : vec){
                cout << i;
            }
            cout << endl << cnt;
            return 0;
        }
        cnt ++;
        vec = addNumber(vec);
    }
    for(int i = vec.size() - 1; i >= 0;i--){
        cout << vec[i];
    }
    cout << endl << cnt;
    return 0;
}