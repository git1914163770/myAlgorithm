#include<iostream>
using namespace std;
int main(){
    int k;
    cin >> k;
    int current = 0;
    int time = 0;
    int t;
    while(k--){
        cin >> t;
        if(t > current) time= time + (t-current)*6+5;
        else if(t <= current) time = time + (current-t)*4 + 5;
        current = t;
    }
    cout << time;
    return 0;
}