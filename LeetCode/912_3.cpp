class Solution {
public:
    // 快速排序 三指针
    static const int INSERTION_SORT_THRESHOLD = 7;

    vector<int> sortArray(vector<int>& nums) {
        srand(time(0));
        int len = nums.size();
        quickSort(nums, 0, len - 1);
        return nums;
    }

private:
    void quickSort(std::vector<int>& nums, int left, int right) {
        // 小区间使用插入排序
        if (right - left <= INSERTION_SORT_THRESHOLD) {
            insertionSort(nums, left, right);
            return;
        }

        int randomIndex = left + rand() % (right - left + 1);
        std::swap(nums[left], nums[randomIndex]);

        int pivot = nums[left];
        int lt = left;
        int gt = right + 1;

        int i = left + 1;
        while (i < gt) {
            if (nums[i] < pivot) {
                lt++;
                std::swap(nums[i], nums[lt]);
                i++;
            } else if (nums[i] == pivot) {
                i++;
            } else {
                gt--;
                std::swap(nums[i], nums[gt]);
            }
        }
        std::swap(nums[left], nums[lt]);

        // 递归调用
        quickSort(nums, left, lt - 1);
        quickSort(nums, gt, right);
    }

    void insertionSort(vector<int>& nums, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            int temp = nums[i];
            int j = i;
            while (j > left && nums[j - 1] > temp) {
                nums[j] = nums[j - 1];
                j--;
            }
            nums[j] = temp;
        }
    }

    void swap(vector<int>& nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
};