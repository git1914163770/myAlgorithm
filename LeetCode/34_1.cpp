// 34. 在排序数组中查找元素的第一个和最后一个位置
class Solution {
public:
    // 按照35题思路想的，分别找到nums[target]+0.1 和nums[target]-0.1的left位置
    // left 位置为第一个大于nums[target]的位置
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0,right = nums.size() - 1;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            if(target < nums[mid]) right = mid - 1;
            else if(target > nums[mid]) left = mid + 1;
            else break; 
        }
        if(left > right) return {-1,-1};
        double leftM = target - 0.1,rightM = target + 0.1;
        left = 0,right = nums.size() - 1;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            if(leftM < nums[mid]) right = mid - 1;
            else if(leftM > nums[mid]) left = mid + 1;
            // else break; 不会有相等的情况，因为输入为整数
        }
        int leftIndex = left;
        left = 0,right = nums.size() - 1;
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            if(rightM < nums[mid]) right = mid - 1;
            else if(rightM > nums[mid]) left = mid + 1;
            // else break; 不会有相等的情况，因为输入为整数
        }
        int rightIndex = left - 1;
        return {leftIndex,rightIndex};
    }
};