#include<iostream>
using namespace std;
// 乙1124
int main(){
    int n;
    cin >> n;

    int a = 0;
    int b = 1;
    int c;
    
    while(1){
        c = a+b;
        if(c>=n){
            if((n-b)<=(c-n)){
                cout << b;
            }else{
                cout << c;
            }
            break;
        }
        a = b;
        b = c;
    }
    return 0;
}