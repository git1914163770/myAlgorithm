// 最小覆盖子串
class Solution {
public:
    string minWindow(string s, string t) {
        // 记录最短子串的开始位置和长度
        int start = 0, minLen = INT_MAX;
        int left = 0, right = 0;
        int setNum = 0;
        int window[128] = {0};
        int needs[128] = {0};
        // unordered_map<char, int> window;
        // unordered_map<char, int> needs;
        for (char c : t) {
            if(needs[c] == 0) setNum++;
            needs[c]++;
        }
        // match 为出现的种类数，当种类数相同匹配成功
        // 或者枚举每个128大小的数组，当window[i] >= need[i] 说明匹配成功
        // https://leetcode.cn/problems/minimum-window-substring/solutions/2713911/liang-chong-fang-fa-cong-o52mn-dao-omnfu-3ezz/
        int match = 0;

        while (right < s.size()) {
            char c1 = s[right];
            if (needs[c1]) {
                window[c1]++;
                if (window[c1] == needs[c1]) 
                    match++;
            }
            right++;

            while (match == setNum) {
                if (right - left < minLen) {
                    // 更新最小子串的位置和长度
                    start = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if (needs[c2]) {
                    window[c2]--;
                    if (window[c2] < needs[c2])
                        match--;
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};