class Solution {
public:
    int mySqrt(int x) {
        long long int left = 1,right = x;
        while(left <= right){
            long long int mid = left + ((right - left) >> 1);
            long long int temp = mid*mid;
            if(temp > x){
                right = mid - 1;
            }else if(temp < x){
                left = mid + 1;
            }else return mid;
        }
        return left - 1;
    }
};