// 49. 字母异位词分组
class Solution {
public:
    //由于互为字母异位词的两个字符串包含的字母相同，因此对两个字符串分别进行排序之后得到的字符串一定是相同的，故可以将排序之后的字符串作为哈希表的键。
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<string>> map;
        for(string s : strs){
            string t = s;
            sort(t.begin(),t.end());
            map[t].push_back(s);
        }
        for (auto it = map.begin(); it != map.end(); ++it){
            res.push_back(it->second);
        }
        return res;
    }
};