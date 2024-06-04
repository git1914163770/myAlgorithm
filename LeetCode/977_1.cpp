// 有序数组的平方
// 选择较大的逆序放
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int left = 0,right = n - 1,pos = n - 1;left <= right;){
            if(nums[left] * nums[left] < nums[right] * nums[right]){
                ans[pos] = nums[right] * nums[right];
                right --;
            }else{
                ans[pos] = nums[left] * nums[left];
                left ++;
            }
            pos --;
        }
        return ans;
    }
};