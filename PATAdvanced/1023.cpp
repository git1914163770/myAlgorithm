#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

vector<int> doubleNumber(vector<int> &vec){
    vector<int> res;
    int carry = 0;
    for(int i = vec.size() - 1;i >=0 ;i--){
        int t = vec[i] * 2 + carry;
        res.push_back(t%10);
        carry = t / 10;
    }
    while(carry != 0){
        res.push_back(carry % 10);
        carry /= 10;
    }
    return res;
} 

// 法一 通过两个vector排序并判等
int main(){
    string s;
    cin >> s;
    vector<int> temp;
    for(int i = 0;i < s.size();i++){
        temp.push_back(s[i] - '0');
    }
    vector<int> res = doubleNumber(temp);
    vector<int> tmp = res;
    sort(tmp.begin(),tmp.end());
    sort(temp.begin(),temp.end());
    if(tmp == temp) cout << "Yes";
    else cout << "No";
    cout << endl;
    for(int i = res.size() - 1;i >= 0;i--){
        cout << res[i];
    }
    return 0;
}

// 法二 设立book来标记数位出现的情况。只有最后book的每个元素都是0的时候才说明这两个数字是相等的一个排列结果