#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int i = s.find('E');
    // while(s[i] != 'E') i++;
    string t = s.substr(1,i-1);
    int e = stoi(s.substr(i+1));
    if(s[0] == '-') printf("-");
    if(e < 0){
        cout<<"0.";
        for(int j = 0;j < abs(e) - 1;j++) printf("0");
        for(int j = 0;j < t.length();j++)
            if(t[j] != '.') cout << t[j];
    } else {
        // 自己想的：如果指数<t.length()-2
        // 那么就从第二个位置起输出指数个字符，再输出点，再输出剩余的
        // 否则，就直接输出剩余的，再补e - (t.length-2)个0
        cout <<t[0];
        int cnt;
        int j;
        for(j = 2,cnt = 0;j < t.length() && cnt < e;j++,cnt++)
            printf("%c",t[j]);
        //已经输出到最后一个字符，补0
        if(j == t.length()){
            for(int k = 0;k < e-cnt;k++) printf("0");
        }else{
            printf(".");
            //从下一个位置全部输出系数
            for(int k = j;k < t.length();k++) printf("%c",t[k]);
        }
    }
    return 0;
}
