#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;

// 乙1100
int main(){
    unordered_set<string> mmap;
    int N,K;
    cin >> N;
    string s;

    for(int i = 0;i<N;i++){
        cin >> s;
        mmap.insert(s);
    }
    cin >> K;
    string olds = "99999999";
    string olds2 = "99999999";//全局

    string st1,st2;
    int count = 0;
    for(int i = 0;i<K;i++){
        cin >> s;
        // 可能来宾比校友年长
        string old = s.substr(6,8);
        if(mmap.count(s)){
            count ++;
            if(old < olds){
                olds = old;
                st1 = s;
            }
        }else{
            if(old < olds2){
                olds2 = old;
                st2 = s;
            }
        }
    }
    if(count > 0){
        cout << count <<endl <<st1;
    }else{
        cout << 0 << endl <<st2;
    }
    return 0;
}