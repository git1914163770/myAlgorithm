class Solution {
private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
public:
    vector<string> res;
    string s;
    void trace(const string& digits,int depth){
        if(digits.size() == depth){
            res.push_back(s);
            return;
        }
        int digit = digits[depth] - '0';
        string temp = letterMap[digit];
        for(int i = 0;i < temp.size();i++){
            s.push_back(temp[i]);
            trace(digits,depth + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        // s.clear();
        // res.clear();
        if(digits.size() == 0){
            return res;
        }
        // 面试中考虑 1 * # 的异常情况
        trace(digits,0);
        return res;
    }
};