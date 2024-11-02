class Solution {
public:
    // 堆排序
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        // 将数组整理成堆
        heapify(nums);

        // 循环不变量：区间 [0, i] 堆有序
        for (int i = len - 1; i >= 1; ) {
            // 把堆顶元素（当前最大）交换到数组末尾
            swap(nums[0], nums[i]);
            // 逐步减少堆有序的部分
            i--;
            // 下标 0 位置下沉操作，使得区间 [0, i] 堆有序
            siftDown(nums, 0, i);
        }
        return nums;
    }

private:
    // 将数组整理成堆（堆有序）
    void heapify(vector<int>& nums) {
        int len = nums.size();
        // 只需要从 i = (len - 1) / 2 这个位置开始逐层下移
        for (int i = (len - 1) / 2; i >= 0; i--) {
            siftDown(nums, i, len - 1);
        }
    }

    // 当前下沉元素的下标 k, [0, end] 是 nums 的有效部分
    void siftDown(vector<int>& nums, int k, int end) {
        while (2 * k + 1 <= end) {
            int j = 2 * k + 1; // 左子节点
            if (j + 1 <= end && nums[j + 1] > nums[j]) {
                j++; // 选择较大的子节点
            }
            if (nums[j] > nums[k]) {
                swap(nums[j], nums[k]); // 交换
            } else {
                break;
            }
            k = j; // 更新 k 为下沉位置
        }
    }
};
