// 分割回文串
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<bool>> f;

    void traceback(string& s,int i){
        if(i == s.size()){
            res.push_back(path);
            return;
        }

        for(int j = i;j < s.size();j++){
            if(f[i][j]){
                string str = s.substr(i,j - i + 1);
                path.push_back(str);
                traceback(s,j+1);
                path.pop_back();
            }
        }
    }

    // 使用动态规划验证是否为回文串
    vector<vector<string>> partition(string s) {
        int n = s.size();
        f.resize(n, vector<bool>(n, true));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
            }
        }
        traceback(s,0);
        return res;
    }

    bool isPalindrom(const string& s,int start,int end){
        for(int i = start,j = end;i < j;i++,j--){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
};