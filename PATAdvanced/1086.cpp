// 3 2 4 1 6 5
// 3 4 2 6 5 1
#include <iostream>
#include <stack>
// 节点被Push, 若上次操作为Push,则它的父节点是上个节点,它为左孩子
// 节点被Push, 若上次操作为Pop,则它的父节点是上个被删除的节点,它为右孩子
// https://blog.csdn.net/Weary_PJ/article/details/124861460
const int N = 40;

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void dfs(TreeNode* node, TreeNode* root) {
    if (node->left) dfs(node->left, root);
    if (node->right) dfs(node->right, root);
    if (node == root) cout << node->val;
    else cout << node->val << " ";
}

int main() {
    int n;
    cin >> n;
    int root_val;
    TreeNode* root = nullptr;
    TreeNode* pre = nullptr;
    int type; // type = 0 上一次是push
    stack<TreeNode*> s;
    for (int i = 0; i < 2 * n; ++i) {
        string op;
        cin >> op;
        if (op == "Push") {
            int x;
            cin >> x;
            TreeNode* node = new TreeNode(x);
            if (!pre) {
                root = node;
            } else {
                if (!type) pre->left = node;
                else pre->right = node;
            }
            s.push(node);
            pre = node;
            type = 0;
        } else {
            type = 1;
            pre = s.top();
            s.pop();
        }
    }
    dfs(root, root);
    return 0;
}

// 法2 https://huixiaoge.blog.csdn.net/article/details/121266786
// 入栈顺序就是树的前序遍历的顺序
// 出栈顺序就是树的中序遍历的顺序
// 故问题，就转换成了根据前序遍历，中序遍历的顺序建树的过程。