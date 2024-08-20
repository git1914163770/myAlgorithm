#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool isPrime(int n){
    if(n < 2) return false;
    for(int i = 2;i <= n / i);i++){
        if(n % i == 0) return false;
    }
    return true;
}

bool check(int n,int d){
    if(!isPrime(n)) return false;
    vector<int> vec;
    do{
        vec.push_back(n % d);
        n /= d;
    }while(n != 0);
    int sum = 0,product = 1;
    for(int i = vec.size() - 1;i >= 0;i--){
        sum += vec[i] * product;
        product *= d;
    }
    return isPrime(sum);
}

int main(){
    int n,d;
    while(1){
        cin >> n;
        if(n < 0) break;
        cin >> d;
        if(check(n,d)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}