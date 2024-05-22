#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    double res = 1.0;
    for(int i = 0;i < 3;i++){
        double a,b,c;
        cin >> a >> b >> c;
        if(a > b && a > c){
            cout << "W ";
            res *= a;
        }else if(b > a && b > c){
            res *= b;
            cout << "T ";
        }else{
            res *= c;
            cout << "L ";
        }
    }
    printf("%.2f",(res*0.65-1)*2);
    return 0;
}