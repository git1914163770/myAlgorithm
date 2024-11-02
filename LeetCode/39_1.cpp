// 39 组合总和
class Solution {
public:
    // vector<vector<int>> res;
    // vector<int> temp;
    // void backtracking(vector<int>& candidates,int target,int sum,int start){
    //     if(sum == target){
    //         res.push_back(temp);
    //         return;
    //     }
    //     if(sum > target){
    //         return;
    //     }
    //     for(int i = start;i < candidates.size();i++){
    //         sum += candidates[i];
    //         temp.push_back(candidates[i]);
    //         backtracking(candidates,target,sum,i);
    //         sum -= candidates[i];
    //         temp.pop_back();
    //     }
    // }

    vector<int> temp;
    vector<vector<int>> res;
    // sum和target可以合并为一个剩余数量参数 初始为target
    void dfs(vector<int>& candidates,int start,int sum,int target){
        if(sum == target){
            res.push_back(temp);
            return;
        }
        // 进一步优化
        // 对总集合排序之后 ,如果下一层的sum（就是本层的 sum + candidates[i]）已经大于target，就可以结束本轮for循环的遍历。
        // 即排序后在ifelse后加return 或者写为
        // for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        for(int i = start;i < candidates.size();i++){
            if(sum + candidates[i] <= target){
                temp.push_back(candidates[i]);
                dfs(candidates,i,sum + candidates[i],target);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // sort(candidates.begin(),candidates.end());
        dfs(candidates,0,0,target);
        return res;
    }
};