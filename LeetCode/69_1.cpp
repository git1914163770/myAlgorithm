// x的平方根
class Solution {
public:
    int mySqrt(int x) {
        long left = 0,right = x;
        int ans = -1;
        while(left <= right) {
            long mid = left + ((right - left) >>1);
            if (mid * mid > x) {
                right = mid - 1;
            }else {
                ans = mid;
                left = mid + 1;
            }
        }
        return ans;
    }
};