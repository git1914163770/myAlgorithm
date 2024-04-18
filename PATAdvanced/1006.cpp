#include<iostream>
using namespace std;

int main(){
    int M;
    cin >>M;
    string earlist,lastlist;
    string login = "24:60:60",logout = "00:00:00";
    while(M--){
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        if(s2 < login){
            login = s2;
            earlist = s1;
        }
        if(s3 > logout){
            logout = s3;
            lastlist = s1;
        }
    }
    cout <<earlist<<" " << lastlist;

    return 0;
}