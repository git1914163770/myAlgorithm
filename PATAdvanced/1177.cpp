#include<iostream>
#include<vector>
#include<string>
using namespace std;

// struct Node{
//     int start;
//     int end;
// };
// 乙1125
int main(){
    // vector<Node> res;
    string s;
    cin>>s;
    string t;
    int k = 0;
    cin>>t;
    int start = 0;
    int end = 0;
    int minStr = s.size();
    int minStart = 0;
    int minEnd = 0;
    for(int i =0;i<s.size();i++){
        if(s[i] != t[0]) continue;
        k = 0;
        start = i;
        for(int j = i;j<s.size();j++){
        
            if(s[j] == t[k]){
                if(k == t.size() - 1){
                    end = j;
                }
                k++;
            }
            if(k>=t.size()){
                break;
            }
        }
        if(k == t.size()){
            // Node n;
            // n.start = start;
            // n.end = end;
            if(end-start<minStr){
                minStr = end-start;
                minStart = start;
                minEnd = end;
            }
                // res.push_back(n);
        }
    }
    // for(int i = 0;i<res.size();i++){
    //     if(res[i].end-res[i].start == minStr){
    //         cout << s.substr(res[i].start,res[i].end-res[i].start+1);
    //         break;
    //     }
    // }
    cout << s.substr(minStart,minEnd-minStart+1);
    // for(int i = minStart;i<=minEnd;i++){
    //     cout << s[i];
    // }
    return 0;
}