#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s;
double sum;
// 乙 1054
bool check(string s){
    if((s[0] == '+' || s[0] == '-') && s.size() == 1) return false;
    if(s[0] == '+' || s[0] == '-') s = s.substr(1);
    int k = 0,index;
    for(int i = 0;i<s.size();i++){
        if(s[i] == '.') k++,index = i+1;  // 让下标从1开始
        else if(s[i] < '0' || s[i] > '9') return false;
    }
    if(k >= 2) return false;
    // 2.合法  2.123 不合法
    if(k==1&&s.size()-index > 2) return false;
    // 类似写法
    // int k = num.find('.');
    // if (k != -1 && num.substr(k).size() > 3) return false;
    return true;
}

int main(){
    cin >>n;
    for(int i = 0;i<n;i++){
        cin >> s;
        if(check(s)){
            double temp = stod(s);
            if(temp>=-1000 && temp <=1000){
                sum += temp;
                cnt++;
            }else{
                cout<<"ERROR: " <<s<< " is not a legal number"<<endl;
            }
        }else{
            cout<<"ERROR: " <<s << " is not a legal number"<<endl;
        }
    }
    if(cnt == 1){
        printf("The average of 1 number is %.2lf",sum);
    }else if(cnt > 1){
        printf("The average of %d numbers is %.2lf",cnt,sum/cnt);
    }else{
        printf("The average of 0 numbers is Undefined");
    }
    return 0;
}