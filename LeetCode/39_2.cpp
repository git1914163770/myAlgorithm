// https://leetcode.cn/problems/combination-sum/solutions/2747858/liang-chong-fang-fa-xuan-huo-bu-xuan-mei-mhf9/
// 选或不选
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int)> dfs = [&](int i, int left) {
            if (left == 0) {
                // 找到一个合法组合
                ans.push_back(path);
                return;
            }

            if (i == candidates.size() || left < candidates[i]) {
                return;
            }

            // 不选
            dfs(i + 1, left);

            // 选
            path.push_back(candidates[i]);
            dfs(i, left - candidates[i]);
            path.pop_back(); // 恢复现场
        };

        dfs(0, target);
        return ans;
    }
};