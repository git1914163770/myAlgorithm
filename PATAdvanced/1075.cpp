// 无法通过编译器 -1;id 00001到N 问题ID 1-N ;
// 按总分排名 输出用户每个题的得分，未提交过打印- ，提交了多个计算最高分
// 00005 2 -1 ，2题编译不通过，输出0。4题未参加，输出-
// 排名递增顺序打印，相同排名按完美解决数递减，最后按ID递增
// 所有题都为-1或-2，不显示在排名(为0的话输出)
// 最后一个测试用例，用户1未提交，总分0，用户2提交1个0分，总分0。应不输出用户1，输出用户2
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct stu{
    int id;
    int rank,total = 0;
    int num = 0; // 完美解决数
    int grade[6] = {-2,-2,-2,-2,-2,-2};
    int isShow = 0;
};

bool cmp(stu s1,stu s2){
    if(s1.isShow != s2.isShow) return s1.isShow > s2.isShow;
    if(s1.total != s2.total) return s1.total > s2.total;
    else if (s1.num != s2.num) return s1.num > s2.num;
    return s1.id < s2.id;
}

int main(){
    int n,k,m;
    scanf("%d%d%d",&n,&k,&m);
    int pgrade[k+1];
    stu students[n+1] = {};
    // for(int i = 1;i <= n;i++){
    //     fill(students[i].grade,students[i].grade+6,-2);
    // }
    for(int i = 1;i <= k;i++){
        scanf("%d",&pgrade[i]);
    }
    int sid,pid,pscore;
    for(int i = 1;i<=m;i++){
        scanf("%d%d%d",&sid,&pid,&pscore);
        if(pscore > students[sid].grade[pid]){
            students[sid].grade[pid] = pscore;
        }
        students[sid].id = sid;
    }
    for(int i = 1;i <= n;i++){
        int show = 0;
        for(int j = 1;j <= k;j++){
            if(students[i].grade[j] != -1 && students[i].grade[j] != -2){
                students[i].total += students[i].grade[j];
                show = 1;
                if(students[i].grade[j] == pgrade[j]){
                    students[i].num++;
                }
            }
        }
        if(show != 0) students[i].isShow = 1;
    }
    sort(students+1,students+1+n,cmp);

    for(int i = 1;i <= n;i++){
        if(students[i].isShow == 0) break;
        // 需对第一个特判。测试用例： 
        // 1 4 1
        // 20 25 25 30
        // 00001 2 0
        // 应输出1 00001 0 - 0 - - PAT缺少这个用例
        if(i != 1 && students[i].total == students[i-1].total) students[i].rank = students[i-1].rank;
        else students[i].rank = i;
        printf("%d %05d %d",students[i].rank,students[i].id,students[i].total);
        for(int j = 1;j <= k;j++){
            if(students[i].grade[j] == -2) printf(" -");
            else if(students[i].grade[j] == -1) printf(" 0");
            else printf(" %d",students[i].grade[j]);
        }
        printf("\n");
    }
    return 0;
}