// 长度最小的子数组
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minn = INT_MAX;
        int sum = 0;
        int j = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            while(sum >= target){
                minn = min(i - j + 1,minn);
                sum -= nums[j];
                j++;
            }
        }
        return minn == INT_MAX ? 0 : minn;
    }
};