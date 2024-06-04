// 有效的完全平方数
class Solution {
public:
    bool isPerfectSquare(int num) {
        int left = 1,right = num,ans = -1;
        while(left <= right){
            long int mid = left + ((right - left) >> 1);
            if((long)mid * mid > num){
                right = mid - 1;
            }else{
                ans = mid;
                left = mid + 1;
            }
        }
        return ans * ans == num;
    }
};