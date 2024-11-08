// 验证二叉搜索树

class Solution {
private:
    vector<int> vec;
    void traversal(TreeNode* root){
        if(root == nullptr) return;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }

public:
    bool isValidBST(TreeNode* root) {
        traversal(root);
        for(int i = 1; i < vec.size(); i++){
            if(vec[i] <= vec[i-1]) return false;
        }
        return true;
    }
};
