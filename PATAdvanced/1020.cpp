#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// 可参考 https://blog.csdn.net/Weary_PJ/article/details/124861460
//https://blog.csdn.net/liuchuo/article/details/52214833
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (postorder.empty()) return NULL;

    int rootValue = postorder[postorder.size() - 1];
    TreeNode* root = new TreeNode(rootValue);
    if(postorder.size() == 1) return root;
    int delimiterIndex = 0;
    for (; delimiterIndex < inorder.size(); delimiterIndex++) {
        if (inorder[delimiterIndex] == rootValue) break;
    }

    vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
    vector<int> rightInorder(inorder.begin() + delimiterIndex + 1, inorder.end());
    vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
    // postorder.pop_back();
    vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end()-1);

    root->left = buildTree(leftInorder, leftPostorder);
    root->right = buildTree(rightInorder, rightPostorder);

    return root;
}

void bfs(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);
    int flag = 0;

    while (!q.empty()) {
        if(flag!=0){
            printf(" ");
        }
        flag = 1;
        TreeNode* node = q.front();
        printf("%d",node->val);
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> postorder(N);
    vector<int> inorder(N);
    for (int i = 0; i < N; i++) {
        scanf("%d",&postorder[i]);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d",&inorder[i]);
    }

    TreeNode* root = buildTree(inorder, postorder);
    bfs(root);

    return 0;
}
