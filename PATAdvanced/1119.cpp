// https://www.bilibili.com/video/BV1Mt4y197kC
#include<iostream>
#include<vector>
using namespace std;
struct node{
    int val;
    node* left = nullptr;
    node* right = nullptr;
};
int n;
int pre[100],post[100];
vector<int> in;
bool unique = true;
// 最后一个参数为子树长度
void bfs(node* &root,int pres,int posts,int l){
    // if(l == 0) return; 左子树一定存在，右子树条件下面加了
    root = new node();
    root->val = pre[pres];
    if(l == 1) return;//即没有左也没有右子树
    int index;
    // 假设左子树不为空，右子树可能为空，先找左子树的根节点
    // 即假设左子树的根节点一定存在
    for(index = posts;index <posts+l;index++){
        if(post[index] == pre[pres+1]) break;
    }
    int leftL = index - posts + 1;
    int rightL = l - 1 - leftL;
    bfs(root->left,pres+1,posts,leftL);
    if(rightL != 0)
        bfs(root->right,pres+1+leftL,index+1,rightL);
    else unique = false;
}

void bfs2(node* root){
    if(root->left != nullptr) bfs2(root->left);
    in.push_back(root->val);
    if(root->right != nullptr) bfs2(root->right);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    node* root = nullptr;
    bfs(root,0,0,n);
    bfs2(root);
    printf("%s\n%d", unique == true ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); i++)
        printf(" %d", in[i]);
    printf("\n");
    return 0;
}

// 法2 假设右子树一定存在
// https://blog.csdn.net/liuchuo/article/details/52505179
void getIn(int preLeft, int preRight, int postLeft, int postRight) {
    if(preLeft == preRight) {
        in.push_back(pre[preLeft]);
        return;
    }
    if (pre[preLeft] == post[postRight]) {
        int i = preLeft + 1;
        while (i <= preRight && pre[i] != post[postRight-1]) i++;
        if (i - preLeft > 1)
            getIn(preLeft + 1, i - 1, postLeft, postLeft + (i - (preLeft + 1) - 1));
        else
            unique = false;
        in.push_back(post[postRight]);
        getIn(i, preRight,postRight - 1 - (preRight - i), postRight - 1);
        // postLeft + (i - (preLeft + 1))可以改为postRight - 1 - (preRight - i)
    }
}