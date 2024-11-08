class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> que;
        if(root != nullptr) que.push(root);
        while(!que.empty()){
            int size = que.size();
            while(size){
                TreeNode* node = que.front();
                que.pop();
                swap(node->left,node->right);
                if(node->left != nullptr) que.push(node->left);
                if(node->right != nullptr) que.push(node->right);
                size--;
            }
        }
        return root;
    }
};