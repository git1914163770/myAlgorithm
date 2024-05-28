#include<bits/stdc++.h>
using namespace std;
struct student{
    string name;
    int height;
};
// 乙1055
bool cmp(student a,student b){
    if(a.height != b.height) return a.height > b.height;
    return a.name < b.name;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<student> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i].name >> v[i].height;
    }
    sort(v.begin(),v.end(),cmp);
    int mcount = 0;
    int index = 0;
    for(int i = k-1;i>=0;i--){
        if(i==k-1) mcount = n/k + n%k;
        else mcount = n / k;
        string temp = v[index++].name;
        int flag = 0;
        for(int j = 2;j <= mcount;j++){
            if(!flag){
                temp = v[index++].name + " " + temp;
                flag = 1;
            }else{
                temp = temp + " " + v[index++].name;
                flag = 0;
            }
        }
        cout << temp << endl;

    }

    return 0;
}