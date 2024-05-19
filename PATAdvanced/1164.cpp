#include<iostream>
#include<string>
using namespace std;

char a[26][7][5];
string s;

// 乙1109
int main(){
    for(int i = 0;i<26;i++){
        for(int j = 0;j<7;j++){
            for(int k = 0;k<5;k++){
                cin >> a[i][j][k];
            }
        }
    }
    getchar();
    getline(cin,s);
    int flag = 0;
    for(int i = 0,fast,flag = 0;i < s.size();i++){
        fast = i;
        while(fast < s.size() && s[fast] >= 'A' && s[fast] <= 'Z') fast ++;
        if(fast == i) continue;
        if(flag) cout << endl;
        flag = 1;
        for(int l = 0;l<7;l++){
            for(int k = i;k<fast;k++){
                if(k != i) cout << " ";
                for(int m = 0;m<5;m++){
                    cout << a[s[k] - 'A'][l][m] ;
                }
            }
            cout << endl;
        }
        
        i = fast;
    }
    
    return 0;
}