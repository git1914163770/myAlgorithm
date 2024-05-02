#include<cstdio>
int main(){
    char c[14] = {"0123456789ABC"};
    printf("#");
    for(int i = 0;i < 3;i++){
        int num;
        scanf("%d",&num);
        // 因为题目范围[0,168] 不会超过2位数
        printf("%c%c",c[num/13],c[num%13]);
    }
    return 0;
}