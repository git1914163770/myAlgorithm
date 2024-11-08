// 二叉树的中序遍历
class Solution {
public:
    vector<int> res;

    void inorder(TreeNode* node){
        if(node == nullptr) return;
        inorder(node->left);
        res.push_back(node->val);
        inorder(node->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return res;
    }
};