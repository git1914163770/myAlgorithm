#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct node{
    int add;
    int data;
    int next;
};

int main(){
    node a[100001];
    vector<node> res;
    int start,n,k;
    cin >> start >> n >> k;
    for(int i = 0;i< n;i++){
        node l;
        cin >> l.add >>l.data >> l.next;
        a[l.add] = l;
    }
    int count = 0;
    while(start != -1){
        res.push_back(a[start]);
        start = a[start].next;
        count ++;
    }
    // auto it = res.begin(); //定义迭代器
    // for(int i = 0; i < res.size() / k; i++){
    //     reverse(it, it + k);	//用reverse函数进行反转
    //     it = it + k; 
    // }

    int pos = 0;
    while(1){
        if(pos + k <= count) reverse(res.begin()+pos,res.begin()+pos + k);
        else break;
        pos += k;
    }
    // next 为逆序后下一个节点的地址
    for(int i = 0;i<count-1;i++){
        printf("%05d %d %05d\n",res[i].add,res[i].data,res[i+1].add);
    }
    // -1 用05d 会出问题，单独处理
    printf("%05d %d -1",res[count - 1].add,res[count - 1].data);
    return 0;
}