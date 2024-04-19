#include<iostream>
#include<map>
#include<unordered_map>
#include<string>
using namespace std;

bool check(char c){
    if(c >= '0' && c <= '9') return true;
    if((c >= 'A' && c <= 'Z') || (c>= 'a' && c<='z')) return true;
    return false;
}

int main(){
    map<string,int> map;
    int index = 0;
    string s;
    getline(cin,s);
    string t;
    for(int i = 0;i < s.size();i++){
        if(check(s[i])){
            s[i] = tolower(s[i]);
            t+= s[i];
        }
        // 注意以字母数字结尾而非双引号结尾的情况
        if(i == s.size() - 1 || !check(s[i])){
            if(t.size() != 0){
                map[t]++;
                t = "";
            }
        }
    }
    int maxn = 0;
    for(auto it = map.begin();it != map.end();it++){
        if(it->second > maxn){
            maxn = it->second;
            t = it->first;
        }
    }
    cout << t << " " << maxn;
    return 0;
}

// 双指针法
int func2(){
    string s1;
    getline(cin, s1);
    unordered_map<string, int> map;
    for (int i = 0; i < s1.size(); ++i) {
        if (check(s1[i])) {
            string cur_s;
            int j = i + 1;
            cur_s += tolower(s1[i]);
            while (j < s1.size()) {
                if (check(s1[j]))
                    cur_s += tolower(s1[j++]);
                else break;
            }
            i = j;
            map[cur_s]++;
        }
    }
    string res;
    int value = 0;
    for (auto item:map) {
        if (item.second > value || (item.second == value && item.first < res)) {
            res = item.first;
            value = item.second;
        }
    }
    cout << res << " " << value << endl;
    return 0;
}