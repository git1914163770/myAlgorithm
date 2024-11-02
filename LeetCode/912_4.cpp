class Solution {
public:
    vector<int> temp;

    // 归并排序
    void mergeSort(vector<int>& nums, int left, int right) {
        // 当元素个数小于 8 时使用插入排序
        if (right - left < 8) {
            insertionSort(nums, left, right);
            return;
        }
        int mid = left + ((right - left) >> 1);
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        // 优化，有序时才合并
        if(nums[mid] > nums[mid + 1])
            merge(nums, left, mid, right);
    }
    
    // 合并两个有序数组
    void merge(vector<int>& nums, int left, int mid, int right){
        int i = left, j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= right) temp[k++] = nums[j++];
        for (int i = left,k = 0; i <= right; i++) nums[i] = temp[k++];
        return;
    }

    void insertionSort(vector<int>& nums, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int key = nums[i];
            int j = i - 1;
            while (j >= left && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        temp.resize(nums.size()); 
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};