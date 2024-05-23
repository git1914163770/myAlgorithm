#include<iostream>
using namespace std;
struct node{
    int lchild,rchild,parent,level;
    node(){
        lchild = rchild = parent = -1;
    }
}Tree[1005];
// https://blog.csdn.net/qq_44799453/article/details/129056229
// 和国内定义不同，满二叉树国内 2^k - 1节点数 应为完美二叉树 Perfect Binary Tree 
// 题目中描述的是Full/Strictly Binary Tree
// https://blog.csdn.net/liuchuo/article/details/126222917
int In[35],Post[35];
int n, m, a, b, root, f, Full;
string t;
// 返回节点下标
int dfs(int il,int ir,int pl,int pr,int parent,int l){
    if(il > ir || pl > pr) return -1;
    int start = il;
    int root = Post[pr];
    while(In[start] != root) start++;
    // Tree[root].parent = parent;
    Tree[root].level = l; // 或者Tree[root].level = Tree[parent].level+1;
    Tree[root].lchild = dfs(il,start-1,pl,pl+start-il-1,root,l+1);
    // 可以将上面的注释改为下面的
    if(Tree[root].lchild != -1) Tree[Tree[root].lchild].parent = root;
    Tree[root].rchild = dfs(start+1,ir,pl+start-il,pr-1,root,l+1);
    // 可以将上面的注释改为下面的
    if(Tree[root].rchild != -1) Tree[Tree[root].rchild].parent = root;

    if(Tree[root].lchild * Tree[root].rchild < 0) Full = 1;
    return root;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> Post[i];
    } 
    for (int i = 0; i < n; i++) 
        cin >> In[i];
    root = Post[n - 1];
    dfs(0,n-1,0,n-1,1001,1);
    cin >> m;
    while (m--) {
        f = 0;
        cin >> t;
        if (t == "It") {
            cin >> t >> t >> t >> t;
            if (Full) cout << "No\n";
            else cout << "Yes\n";
            continue;
        } 
        a = stoi(t);
        cin >> t;
        if (t == "is") {
            cin >> t >> t;
            if (t == "root") {
                if (a == root) f = 1;
            } else if (t == "parent") {
                cin >> t >> b;
                if (Tree[b].parent == a) f = 1;
            } else if (t == "left") {
                cin >> t >> t >> b;
                if (Tree[b].lchild == a) f = 1;
            } else {
                cin >> t >> t >> b;
                if (Tree[b].rchild == a) f = 1;
            }
        } else {
            cin >> b >> t >> t;
            if (t == "siblings") {
                if (Tree[a].parent == Tree[b].parent) f = 1;
            } else {
                cin >> t >> t >> t;
                if (Tree[a].level == Tree[b].level) f = 1;
            }
        }
        cout << (f ? "Yes\n" : "No\n");
    }
    return 0;
}