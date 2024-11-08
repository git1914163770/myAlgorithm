class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if(!root) return result;
        TreeNode* node = root;
        // 栈为空但 node 不为空的情况发生在已经处理了某个节点的左子树并且准备处理它的右子树时
        // stack 为历史节点 node 为正在访问的节点
        while (!st.empty() || node != nullptr) {
            // 遍历到最左边的节点
            while (node != nullptr) {
                st.push(node);
                node = node->left;
            }
            // 当前节点就是最左边的节点
            node = st.top();
            st.pop();
            result.push_back(node->val); // 访问节点值

            // 处理右子树
            node = node->right;
        }
        return result;
    }
};