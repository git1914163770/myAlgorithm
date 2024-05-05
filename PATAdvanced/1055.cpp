#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100001;
struct Person{
    int age,worths;
    char name[10];
}ps[maxn];
bool cmp(Person p1,Person p2){
    if(p1.worths != p2.worths) return p1.worths > p2.worths;
    if(p1.age != p2.age) return p1.age < p2.age;
    return strcmp(p1.name,p2.name) < 0;
}
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n;i++){
        scanf("%s%d%d",ps[i].name,&ps[i].age,&ps[i].worths);
    }
    sort(ps,ps+n,cmp);
    int m,min,max;
    for(int i = 1;i <=k;i++){
        scanf("%d%d%d",&m,&min,&max);
        printf("Case #%d:\n",i);
        int printNum = 0;//已输出的人数
        int j = 0;
        while(printNum < m && j < n){
            if(ps[j].age >= min && ps[j].age <=max){
                printf("%s %d %d\n",ps[j].name,ps[j].age,ps[j].worths);
                printNum ++;
            }
            j++;
        }
        if(printNum == 0){
            printf("None\n");
        }

    }
    return 0;
}