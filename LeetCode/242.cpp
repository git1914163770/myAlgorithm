// 242. 有效的字母异位词
class Solution {
public:
    bool isAnagram(string s, string t) {
        int visit[26] = {0};
        for(char c:s){
            visit[c-'a']++;
        }
        for(char c:t){
            visit[c-'a']--;
        }
        for(int i = 0;i < 26;i++){
            if(visit[i] != 0) return false;
        }
        return true;
    }
};