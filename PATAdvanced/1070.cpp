#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct mooncake {
    // 月饼的库存量和总售价并没有说是正整数，可能是浮点类型
    float store;
    float sell;
    float price;
};

bool cmp(mooncake a,mooncake b){
    return a.price > b.price;
}

int main(){
    int n,need;
    cin >> n >> need;
    vector<mooncake> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i].store;
    }
    for(int i = 0;i<n;i++){
        cin >>v[i].sell;
        v[i].price = v[i].sell / v[i].store;
    }
    sort(v.begin(),v.end(),cmp);
    float res = 0.0;
    for(int i = 0;i<n;i++){
        if(v[i].store > need) {
            res += v[i].price * need;
            break;
        }else{
            res += v[i].sell;
            need -= v[i].store;
        }
    }
    printf("%.2f",res);
    return 0;
}