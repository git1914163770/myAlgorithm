// 比较含退格的字符串
class Solution {
public:
    void build(string &s,stack<char> &st){
        for(int i = 0;i < s.size();i++){
            if(s[i] == '#' && !st.empty()){
                st.pop();
            }else if(s[i] != '#'){
                st.push(s[i]);
            }
        }
    }
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        build(s,s1);
        build(t,s2);
        while(!s1.empty() && !s2.empty()){
            if(s1.top() != s2.top()) return false;
            s1.pop();s2.pop();
        }
        return s1.empty() && s2.empty();
    }
};