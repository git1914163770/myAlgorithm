#include<iostream>
#include<vector>
#include<string>

using namespace std;
struct node{
    string val;
    int left,right;
};

vector<node> v;
bool father[30],is_leaf[30];

string dfs(int index){
    string left,right;
    if(v[index].left != -1){
        left = dfs(v[index].left);
        if(!is_leaf[v[index].left]) left = "(" + left + ")";
    }
    if(v[index].right != -1){
        right = dfs(v[index].right);
        if(!is_leaf[v[index].right]) right = "(" + right + ")";
    }
    return left + v[index].val + right;
}

int main(){
    int n;
    cin >> n;
    int root = 1;
    v.resize(n+1);
    for(int i = 1;i <= n;i++){
        cin >> v[i].val >> v[i].left >> v[i].right;
        if(v[i].left != -1) father[v[i].left] = true;
        if(v[i].right != -1) father[v[i].right] = true;
        if(v[i].left == -1 && v[i].right == -1) is_leaf[i] = true;
    }
    while(father[root]) root++;
    cout << dfs(root) << endl;
    return 0;
}