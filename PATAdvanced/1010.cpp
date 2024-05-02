#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

int getN(char c){
    if(c <= '9') return c - '0';
    else return c - 'a' + 10;
}

long long convert(string s,int radix){
    long long sum = 0;
    long long product = 1;
    for(int i = s.size() - 1;i >= 0;i--){
        sum += getN(s[i]) * product;
        product *= radix;
    }
    return sum;
}

long long findRadix(string s1,int radix,string s2){
    // 从最大数字+1开始尝试
    int maxDigit = 0;
    for(int i = 0;i < s2.size();i++){
        if(getN(s2[i]) > maxDigit) maxDigit = getN(s2[i]);
    }
    long long num = convert(s1,radix);
    
    // for(long long i = maxDigit+1;i <= INT_MAX;i++){
    //     long long t = convert(s2,i);
    //     if(num == t){
    //         return i;
    //     }
    //     if(t < 0) return -1;
    // }

    long long low = maxDigit + 1;
    long long high = INT_MAX;
    if(convert(s2,maxDigit+1) == convert(s2,maxDigit)){
        return low;
    }
    // 或者上面两步改为
    //    long long high = max(num, low);
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = convert(s2, mid);
        if (t < 0 || t > num) high = mid - 1;
        else if (t == num){
            return mid;
        }else low = mid + 1;
    }
    return -1;
}

// 坑点 radix可能达到INT_MAX
// 对于6 110 2 2 应输出7而不是10
int main(){
    string N1,N2;
    int tag,radix;
    cin >> N1 >> N2 >> tag >> radix;
    if(tag == 2) swap(N1,N2);
    long long res = findRadix(N1,radix,N2);
    if(res != -1){
        cout << res;
    }else{
        cout << "Impossible";
    }

    return 0;
}