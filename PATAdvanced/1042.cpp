#include<cstdio>
#include<algorithm>

char mp[5] = {'S','H','C','D','J'};

int start[55],move[55];
int next[55];
int main(){
    int repeat = 0;

    scanf("%d",&repeat);
    //初始化
    for(int i = 1;i <= 54;i++){
        start[i] = i;
    }
    //输入每个位置
    for(int i = 1;i <= 54;i++){
        scanf("%d",&next[i]);
    }
    for(int step = 0;step < repeat;step++){
        for(int i = 1;i <=54;i++){
            move[next[i]] = start[i];
        }
        for(int i = 1;i <=54;i++){
            start[i] = move[i]; //赋值给start以供下次使用
        }
    }
    for(int i = 1;i<=54;i++){
        if(i != 1) printf(" ");
        printf("%c%d",mp[(start[i]-1)/13],(start[i]-1)%13+1);
    }

    return 0;
}