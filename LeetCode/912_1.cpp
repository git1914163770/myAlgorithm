#include<iostream>
using namespace std;

// 插入排序
void insertSort(vector<int>& nums){
    int len = nums.size();
    for(int i = 1; i < len; i++){
        // 先暂存这个留存，之前的元素后移，留出空位
        int temp = nums[i];
        int j = i;
        // 左闭右开区间
        // j > 0 可以理解为最后退出时刚好为>=0
        // 或者由于j - 1 >= 0
        while(j > 0 && nums[j - 1] > temp){
            nums[j] = nums[j - 1];
            j--;
        }
        nums[j] = temp;
    }
}