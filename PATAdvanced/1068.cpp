#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX_N = 10001;
int nums[MAX_N];
int n,s;
int foundf = false;

// start 表示当前遍历的元素下标
void findCombination(int start, int target, vector<int>& currentCombination, vector<int>& bestCombination) {
    if (target == 0) {
        // 找到一个满足条件的组合，检查是否是最小组合
        if (bestCombination.empty() || currentCombination < bestCombination) {
            bestCombination = currentCombination;
        }
        foundf = true;
        return;
    }

    // if (target < 0 || start >= n) {
    //     // 超过了目标值或数组边界，回溯
    //     return;
    // }
    
    bool found = false;
    for (int i = start; i < n; ++i) {
        // 剪枝：如果当前元素已经超过目标值，则停止后续的尝试
        if (nums[i] > target) break;
        // 避免重复的组合 如 4,3 1 1 1 1
        // 1 1 1(选) 1(不选) 和 1 1 1（不选）1（选）
        if (i > start && nums[i] == nums[i - 1]) continue;

        currentCombination.push_back(nums[i]);
        findCombination(i + 1, target - nums[i], currentCombination, bestCombination);
        currentCombination.pop_back(); // 回溯
    }
    
    return;
}

int main() {
    scanf("%d %d",&n,&s);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d",&nums[i]);
    }
    
    sort(nums, nums+n); // 先排序以确保组合按从小到大顺序
    
    vector<int> currentCombination;
    vector<int> bestCombination;
    
    findCombination(0, s, currentCombination, bestCombination);
    if(!foundf){
        printf("No Solution\n");
    } else {
        int flag = 0;
        for (int num : bestCombination) {
            if(flag) printf(" ");
            else flag = 1;
            printf("%d",num);
        }
    }
    
    return 0;
}
