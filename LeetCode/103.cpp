// 二叉树的锯齿形层序遍历
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        bool isOrderLeft = true;

        while (!nodeQueue.empty()) {
            deque<int> levelList;
            int size = nodeQueue.size();
            for (int i = 0; i < size; ++i) {
                auto node = nodeQueue.front();
                nodeQueue.pop();
                if (isOrderLeft) {
                    levelList.push_back(node->val);
                } else {
                    levelList.push_front(node->val);
                }
                if (node->left) nodeQueue.push(node->left);
                if (node->right) nodeQueue.push(node->right);
            }
            ans.emplace_back(vector<int>(levelList.begin(), levelList.end()));
            isOrderLeft = !isOrderLeft;
        }

        return ans;
    }
};

// 类似的方法 使用vector的insert
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode*> q;
        if(root != nullptr) q.push_back(root);
        bool leftToRight = true;

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> level;
            while(levelSize){
                levelSize--;
                TreeNode* node = q.front();
                q.pop_front();
                if(leftToRight){
                    level.push_back(node->val);
                }else{
                    level.insert(level.begin(),node->val);
                }
                if(node->left) q.push_back(node->left);
                if(node->right) q.push_back(node->right);
            }
            res.push_back(level);
            leftToRight = !leftToRight;
        }
        return res;
    }
};