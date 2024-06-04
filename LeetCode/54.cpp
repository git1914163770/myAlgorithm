// 螺旋矩阵
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        int count = 0;
        int sum = m * n;
        vector<int> res(m * n);
        int i, j;
        while (count < sum) {
            i = top, j = left;
            while (j <= right && count < sum) {
                res[count] = matrix[i][j];
                count++;
                j++;
            }
            
            // Traverse from top to bottom
            i = top + 1, j = right;
            while (i <= bottom && count < sum) {
                res[count] = matrix[i][j];
                count++;
                i++;
            }
            
            i = bottom, j = right - 1;
            while (j >= left && count < sum) {
                res[count] = matrix[i][j];
                count++;
                j--;
            }
            
            // Traverse from bottom to top
            i = bottom - 1, j = left;
            while (i > top && count < sum) {
                res[count] = matrix[i][j];
                count++;
                i--;
            }
            
            // Update the boundaries
            top++, left++, bottom--, right--;
        }
        
        return res;
    }
};