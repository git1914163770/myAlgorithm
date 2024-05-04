#include<algorithm>
#include<string>
#include<cstdio>
using namespace std;
struct Student{
    int id;
    int best ; //0 1 2 3
    int score[4],rank[4];//A C M E
}stu[2001];
//或者map<int,Student>
int flag = -1;
bool cmpl(Student a,Student b){return a.score[flag] > b.score[flag];}
int exist[1000001];
int main(){
    fill(exist,exist+1000000,-1);
    int m,n;
    scanf("%d %d",&n,&m);
    for(int i = 0;i< n;i++){
        scanf("%d %d %d %d",&stu[i].id,&stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        // 是否要四舍五入？
        stu[i].score[0] = (stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3.0 + 0.5;
    }
    // 对于同分的怎么处理？
    for(flag = 0;flag <= 3;flag++){
        sort(stu,stu+n,cmpl);
        stu[0].rank[flag] = 1;
        for(int i = 1;i < n;i++){
            stu[i].rank[flag] = i + 1;
            if(stu[i].score[flag] == stu[i-1].score[flag]){
                stu[i].rank[flag] = stu[i - 1].rank[flag];
            }
        }
    }
    for(int i = 0;i < n;i++){
        exist[stu[i].id] = i;//结构体中的位置
        stu[i].best = 0;
        int minn = stu[i].rank[0];
        for(int j = 1;j <=3;j++){
            if(stu[i].rank[j] < minn){
                minn = stu[i].rank[j];
                stu[i].best = j;
            }
        }
    }
    // char c[5] = {'A','C','M','E'};
    string c = "ACME";
    int id;
    for(int i = 0;i < m;i++){
        scanf("%d",&id);
        int temp = exist[id];
        if(temp != -1){
            int best = stu[temp].best;
            //输出排名和位置符号
            printf("%d %c\n",stu[temp].rank[best],c[best]);
        }else{
            printf("N/A\n");
        }
    }
    return 0;
}