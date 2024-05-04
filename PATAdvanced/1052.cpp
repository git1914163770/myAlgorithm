#include<iostream>
#include<algorithm>
using namespace std;

struct node{
    int address;
    int data;
    int next;
};

node temp[100005] = {};
node nodearr[100005] = {};

bool cmp(node n1,node n2){
    return n1.data < n2.data;
}


int main(){
    int n,start;
    scanf("%d %d",&n,&start);
    int k = 0;
    int a,d,next;
    for(int i = 0;i < n;i++){
        scanf("%d%d%d",&a,&d,&next);
        temp[a] = {a,d,next};
    }

    int cnt = 0;
    while(start != -1){
        nodearr[cnt].address = start;
        nodearr[cnt].data = temp[start].data;
        start = temp[start].next;
        cnt++;
    }
    if(cnt == 0){
        printf("0 -1");
        return 0;
    }
    sort(nodearr,nodearr+cnt,cmp);
    printf("%d %05d\n",cnt,nodearr[0].address);
    for(int i = 0;i < cnt-1;i++){
        printf("%05d %d %05d\n",nodearr[i].address,nodearr[i].data,nodearr[i+1].address);
    }
    printf("%05d %d -1",nodearr[cnt-1].address,nodearr[cnt-1].data);
    
    return 0;
}