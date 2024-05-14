#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
// 待修改
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int inStart, int inEnd, int postStart, int postEnd, unordered_map<int, int>& inorderMap) {
    if (inStart > inEnd || postStart > postEnd) return nullptr;

    int rootVal = postorder[postEnd];
    TreeNode* root = new TreeNode(rootVal);

    int rootIndex = inorderMap[rootVal];
    int leftSize = rootIndex - inStart;
    int rightSize = inEnd - rootIndex;

    root->left = buildTree(inorder, postorder, inStart, rootIndex - 1, postStart, postStart + leftSize - 1, inorderMap);
    root->right = buildTree(inorder, postorder, rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1, inorderMap);

    return root;
}

int flag = false;
void zigzagLevelOrder(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> levels[2];
    int currentLevel = 0;
    levels[currentLevel].push(root);

    while (!levels[0].empty() || !levels[1].empty()) {
        TreeNode* node = levels[currentLevel].top();
        levels[currentLevel].pop();
        if(flag){
            printf(" ");
        }else{
            flag = true;
        }

        cout << node->val;

        if (currentLevel == 0) {
            if (node->right) levels[1].push(node->right);
            if (node->left) levels[1].push(node->left);
        } else {
            if (node->left) levels[0].push(node->left);
            if (node->right) levels[0].push(node->right);
        }

        if (levels[currentLevel].empty()) {
            currentLevel = 1 - currentLevel;
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> inorder(N);
    vector<int> postorder(N);
    unordered_map<int, int> inorderMap;

    for (int i = 0; i < N; ++i) {
        cin >> inorder[i];
        inorderMap[inorder[i]] = i;
    }

    for (int i = 0; i < N; ++i) {
        cin >> postorder[i];
    }

    TreeNode* root = buildTree(inorder, postorder, 0, N - 1, 0, N - 1, inorderMap);
    zigzagLevelOrder(root);

    return 0;
}
