#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int v):val(v),left(nullptr),right(nullptr){}
};
int tree[35];

node* build(int l,int r){
    if(l > r) return nullptr;
    int minn = tree[l];
    int t = l;
    for(int i = l + 1;i <= r;i++){
        if(tree[i] < minn){
            minn = tree[i];
            t = i;
        }
    }
    node* root = new node(minn);
    root->left = build(l,t-1);
    root->right = build(t+1,r);
    return root;
}

void bfs(node* root){
    queue<node*> q;
    int f = 1;
    q.push(root);
    while(!q.empty()){
        node* t = q.front();
        if(!f) printf(" "); else f = 0;
        printf("%d",t->val);
        q.pop();
        if(t->left != nullptr) q.push(t->left);
        if(t->right != nullptr) q.push(t->right);
    }
}

// 其他方法：类似于完全二叉树遍历
// 将根结点的序号设为1，左孩子的序号为它的两倍，右孩子的序号为它的两倍+1，
// 最后根据序号顺序输出ans即为层序遍历的顺序
// https://blog.csdn.net/liuchuo/article/details/126225290

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
       scanf("%d",&tree[i]); 
    }
    node* root = build(0,n-1);
    bfs(root);
    return 0;
}