#include<cstdio>
struct Student{
    char name[12];
    char id[12];
    int score;
}F,M,temp;
int main(){
    M.score = 101;
    F.score = -1;
    int n;
    scanf("%d",&n);
    char gender;
    for(int i = 0;i<n;i++){
        scanf("%s %c %s %d",temp.name,&gender,temp.id,&temp.score);
        if(gender == 'M' && M.score > temp.score){
            M = temp;
        }else if(gender == 'F' && F.score < temp.score){
            F = temp;
        }
    }
    if(F.score == -1)printf("Absent\n");
    else printf("%s %s\n",F.name,F.id);
    if(M.score == 101) printf("Absent\n");
    else printf("%s %s\n",M.name,M.id);
    if(F.score == -1 || M.score == 101) printf("NA");
    else printf("%d",F.score - M.score);
    return 0;
}