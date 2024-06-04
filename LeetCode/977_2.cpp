class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> v(nums.size());
        while(left <= right){
            int mid = left + ((right - left) >> 1);
            if(nums[mid] < 0){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        int leftEnd = left - 1;
        int rightS = left;
        int index = 0;
        // cout << leftEnd << " " << rightS;
        while(rightS < nums.size() && leftEnd >= 0){
            if(abs(nums[leftEnd]) < abs(nums[rightS])){
                v[index++] = nums[leftEnd] * nums[leftEnd];
                leftEnd--;
            }else if(abs(nums[leftEnd]) >= abs(nums[rightS])){
                v[index++] = nums[rightS] * nums[rightS];
                rightS++;
            }
        }
        while(rightS < nums.size()){
            v[index++] = nums[rightS] * nums[rightS];
            rightS++;
        }
        while(leftEnd >= 0){
            v[index++] = nums[leftEnd] * nums[leftEnd];
            leftEnd--;
        }
        return v;
    }
};