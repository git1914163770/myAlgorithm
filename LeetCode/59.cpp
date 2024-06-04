// 螺旋矩阵 II
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int left = 0,right = n - 1;
        int top = 0,bottom = n - 1;
        int loop = n / 2;
        int mid = n / 2;
        int count = 1;
       
        int i,j;
        while(loop --){
            i = top;
            j = left;
            for(;j < right;j++){
                res[i][j] = count ++;
            }
            for(;i < bottom;i++){
                res[i][j] = count++;
            }
            for(;j > left;j--){
                res[i][j] = count++;
            }
            for(;i > top;i--){
                res[i][j] = count++;
            }

            top++;
            right--;
            bottom--;
            left++;
        }
        if(n % 2 == 1){
            res[mid][mid] = count;
        }
        return res;
    }

};