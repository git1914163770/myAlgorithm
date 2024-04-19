#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

int main(){
    unordered_set<char> set;
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for(char c:s2){
        set.insert(c);
    }
    for(char c:s1){
        if(set.find(c) == set.end()){
            cout << c;
        }
    }
    return 0;
}