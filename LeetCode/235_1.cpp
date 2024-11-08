// 二叉搜索树的最近公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val = root->val;
        if(p->val > val && q->val > val){
            return lowestCommonAncestor(root->right,p,q);
        }else if(p->val < val && q->val < val){
            return lowestCommonAncestor(root->left,p,q);
        }else{
            return root;
        }
    }
};