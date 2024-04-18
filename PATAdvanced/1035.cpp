#include<iostream>
using namespace std;
struct account{
    string s1,s2;
    int modified = 0;
}a[1001];

int judge(char &c){
    if(c == '0') c='%';
    else if(c == '1')c = '@';
    else if(c == 'O')c = 'o';
    else if(c == 'l')c = 'L';
    else return 0;
    return 1;
}

int main(){
    int N;
    cin >> N;
    for(int i = 0;i<N;i++){
        cin >> a[i].s1 >> a[i].s2;
    }
    int count = 0;
    for(int i = 0;i < N;i++){
        for(char &c : a[i].s2){  
            if(judge(c)){
                a[i].modified = 1;
            }
        }
        if(a[i].modified) count ++;
    }
    if(count){
        cout<<count<<endl;
        for(int i = 0;i<N;i++){
            if(a[i].modified){
                cout<<a[i].s1 << ' ' <<a[i].s2<<endl;
            }
        }
    }else{
         if(N>1){
             cout <<"There are " << N << " accounts and no account is modified";
         }else{
             cout << "There is 1 account and no account is modified";
         }
    }
    return 0;
}