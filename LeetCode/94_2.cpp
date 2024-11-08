// https://leetcode.cn/problems/binary-tree-inorder-traversal/solutions/25220/yan-se-biao-ji-fa-yi-chong-tong-yong-qie-jian-ming/
// 二叉树的中序遍历
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        enum Color { WHITE, GRAY };
        std::vector<int> res;
        std::stack<std::pair<Color, TreeNode*>> stack;
        
        stack.push({WHITE, root});
        
        while (!stack.empty()) {
            auto [color, node] = stack.top();
            stack.pop();
            
            if (node == nullptr) continue;
            
            if (color == WHITE) {
                stack.push({WHITE, node->right});
                stack.push({GRAY, node});
                stack.push({WHITE, node->left});
            } else {
                res.push_back(node->val);
            }
        }
        
        return res;
    }
};