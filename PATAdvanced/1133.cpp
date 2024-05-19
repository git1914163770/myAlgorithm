#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct node{
    int address;
    int data;
    int next;
};

// 乙1075
int main(){
    node a[100001];
    node res[100001];
    vector<node> vec;
    
    int start,n,k;
    cin >> start >> n >> k;
    for(int i = 0;i<n;i++){
        node n;
        cin >> n. address >> n.data >> n.next;
        a[n.address] = n;
    }
    while(start != -1){
        vec.push_back(a[start]);
        start = a[start].next;
    }
    int index = 0;
    for(int i = 0;i<vec.size();i++){
        if(vec[i].data<0) res[index++] = vec[i];
    }
    for(int i = 0;i<vec.size();i++){
        if(vec[i].data>=0 && vec[i].data <= k) res[index++] = vec[i];
    }
    for(int i = 0;i<vec.size();i++){
        if(vec[i].data > k) res[index++] = vec[i];
    }
    for(int i = 0;i<vec.size();i++){
        if(i+1!=vec.size())printf("%05d %d %05d\n",res[i].address,res[i].data,res[i+1].address);
        else printf("%05d %d -1",res[i].address,res[i].data);
    }


    return 0;
}