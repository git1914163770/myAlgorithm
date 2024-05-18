#include<iostream>
#include<map>
#include<string>
using namespace std;

// 乙 1069
int main(){
    int m,k,s;
    cin >> m >> k >> s;
    map<string,int> mmap;
    string temp;
    if(s > m){
        cout << "Keep going...";
        return 0;
    }
    for(int i = 1;i<=m;i++){
        cin >> temp;
        if(i==s){
            if(mmap[temp] == 1){
                s++;
                continue;
            }
            mmap[temp] = 1;
            cout << temp<<endl;
            s+=k;
        }
    }

    return 0;
}