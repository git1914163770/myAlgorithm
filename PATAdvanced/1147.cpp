// 甲级1155
#include<iostream>
#include<vector>
using namespace std;

int tree[1005];
int m,n;

void postOrder(int index){
    if(index > n) return;
    postOrder(index * 2);
    postOrder(index * 2 + 1);
    printf("%d%s",tree[index],index == 1? "\n" : " ");
}

int main(){
    scanf("%d %d",&m,&n);
    while(m--){
        int minn = 1,maxn = 1;
        for(int i = 1;i <= n;i++) scanf("%d",&tree[i]);
        for(int i = 2;i <= n;i++){
            if(tree[i] > tree[i/2]) maxn = 0;
            if(tree[i] < tree[i/2]) minn = 0;
        }
        if(maxn == 1) printf("Max Heap\n");
        else if(minn == 1) printf("Min Heap\n");
        else printf("Not Heap\n");
        postOrder(1);
    }
    return 0;
}