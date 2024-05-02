#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

int main(){
    int K;
    map<int,double> poly;
    cin >>K;
    while(K--){
        int n;
        double d;
        cin>>n>>d;
        poly[n] += d; 
    }
    cin >>K;
    while(K--){
        int n;
        double d;
        cin>>n>>d;
        poly[n] += d;
        if(poly[n] == 0)poly.erase(n);
    }
    cout<<poly.size();
    //poly.rbegin();poly.rend();it++
    for(auto it = poly.end();it!=poly.begin();){
        --it;//poly.end()不能使用
        printf(" %d %.1f",it->first,it->second);
    }
}