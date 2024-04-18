#include<iostream>
using namespace std;
string s[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
    int sum = 0;
    // char c;
    // while(isdigit(c = getchar())){
    //     sum += c - '0';
    // }
    string a;
    cin >> a;
    for (int i = 0; i < a.length(); i++)
        sum += (a[i] - '0');
    string temp = to_string(sum);
    cout << s[temp[0] - '0'];
    for(int i = 1;i < temp.size();i++){
        cout <<" ";
        cout << s[temp[i] - '0'];
    }
}