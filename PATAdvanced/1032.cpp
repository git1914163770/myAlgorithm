#include<iostream>
#include<cstdio>
using namespace std;

int Node[100001];
int s1,s2,n;

int main(){
    scanf("%d %d %d",&s1,&s2,&n);
    int a,c;
    char b;
    while(n--){
        scanf("%d %c %d",&a,&b,&c);
        Node[a] = c;
    }
    int t1 = s1,t2 = s2;
    while(t1 != t2){
        if(t1 == -1) t1 = s2;
        else t1 = Node[t1];
        if(t2 == -1) t2 = s1;
        else t2 = Node[t2];
    }
    if(t1 != -1)
        printf("%05d",t1);
    else printf("-1");
    return 0;
}