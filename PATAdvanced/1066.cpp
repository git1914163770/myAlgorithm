#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// 类似1123
struct node{
    int val;
    node *left,*right;
};

node* leftRotate(node* root){
    node* temp = root->right;
    root-> right = temp->left;
    temp->left = root;
    return temp;
}

node* rightRotate(node* root){
    node* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    return temp;
}

int getHeight(node* root){
    if(root == NULL) return 0;
    int l = getHeight(root->left);
    int r = getHeight(root->right);
    return max(l,r) + 1;
}

node* insert(node* root,int val){
    if(root == NULL){
        root = new node();
        root->val = val;
    }else if(val < root->val){
        root->left = insert(root->left,val);
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        if(l - r == 2){
            if(val < root->left->val){
                root = rightRotate(root);
            }else{
                root->left = leftRotate(root->left);
                root = rightRotate(root);
            }
        }
    }else{
        root->right = insert(root->right,val);
        int l = getHeight(root->left);
        int r = getHeight(root->right);
        if(r - l == 2){
            if(val > root->right->val){
                root = leftRotate(root);
            }else{
                root ->right = rightRotate(root->right);
                root = leftRotate(root);
            }
        }
    }
    return root;
}

int main(){
    int n,temp;
    scanf("%d",&n);
    node* root = NULL;
    for(int i = 0;i < n;i++){
        scanf("%d",&temp);
        root = insert(root,temp);
    }
    printf("%d",root->val);
    return 0;
}