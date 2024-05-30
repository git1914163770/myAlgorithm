#include <iostream>
#include <vector>
using namespace std;
struct node {
    int v;
    struct node *left, *right;
    node(int val):v(val),left(nullptr),right(nullptr) {}
};
node* build(node* root, int v) {
    if(root == NULL) {
        root = new node(v);
    } else if(v <= root->v)
        root->left = build(root->left, v);
    else
        root->right = build(root->right, v);
    return root;
}
int num[1000];
int maxdepth = -1;
void dfs(node *root, int depth) {
    if(root == NULL) {
        return;
    }
    maxdepth = max(depth, maxdepth);
    num[depth]++;
    dfs(root->left, depth + 1);
    dfs(root->right, depth + 1);
}
int main() {
    int n, t;
    scanf("%d", &n);
    node *root = NULL;
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        root = build(root, t);
    }
    dfs(root, 0);
    printf("%d + %d = %d", num[maxdepth], num[maxdepth-1], num[maxdepth] + num[maxdepth-1]);
    return 0;
}