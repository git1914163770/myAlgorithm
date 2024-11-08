// 102 二叉树的层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> res;
        if(root != nullptr) que.push(root);
        vector<int> temp;
        while(!que.empty()){
            int size = que.size();
            for(int i = 0;i < size;i++){
                TreeNode* node = que.front();
                que.pop();
                temp.push_back(node->val);
                if(node->left != nullptr) que.push(node->left);
                if(node->right != nullptr) que.push(node->right);
            }
            res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */