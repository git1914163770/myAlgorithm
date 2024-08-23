#include<iostream>
#include<cstdio>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

int postOrder[35],inOrder[30];
unordered_map<int,int> pos;
vector<int> res;

//其他方法 不用bfs 根据节点下标赋值
//https://blog.csdn.net/liuchuo/article/details/52137796
//甲级1159

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(int postStart,int postEnd,int inStart,int inEnd){
    if(postStart>postEnd) return NULL;
    int root=postOrder[postEnd];
    TreeNode* rootNode=new TreeNode(root);
    // int k=inStart;
    // while(inOrder[k]!=root) k++;
    int k=pos[root];
    int leftNum=k-inStart;
    rootNode->left = buildTree(postStart,postStart+leftNum-1,inStart,k-1);
    rootNode->right = buildTree(postStart+leftNum,postEnd-1,k+1,inEnd);
    return rootNode;
}

void bfs(TreeNode* root){
    if(root==NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        res.push_back(node->val);
        if(node->left!=NULL) q.push(node->left);
        if(node->right!=NULL) q.push(node->right);
    }
}

int main(){

    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&postOrder[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&inOrder[i]);
        pos[inOrder[i]]=i;
    }
    TreeNode* root = buildTree(0,n-1,0,n-1);
    bfs(root);
    for(int i=0;i<res.size();i++){
        if(i!=0) printf(" ");
        printf("%d",res[i]);
    }
    return 0;
}