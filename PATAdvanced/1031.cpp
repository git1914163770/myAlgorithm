#include<cstdio>
#include<cstring>
char str[90];
int main(){
    scanf("%s",str);
    int N = strlen(str);
    int n1 = (N+2)/3,n3 = n1,n2 = N+2 -n1 -n3;
    //输出前n1-1行
    for(int i = 0;i<n1-1;i++){
        printf("%c",str[i]);//先输出当前行左侧字符
        //输出空格
        for(int j = 0;j < n2-2;j++){
            printf(" ");
        }
        printf("%c\n",str[N-1-i]);
    }
    for(int i = 0;i<n2;i++){
        printf("%c",str[n1-1+i]);
    }
    return 0;
}