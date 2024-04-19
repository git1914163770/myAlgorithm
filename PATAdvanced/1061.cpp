#include<cstdio>
#include<iostream>
using namespace std;

string week[7] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main(){
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int day;
    int i,j,k;
    //肯定有结果，无需判断size()
    for(i = 0;;i++){
        if(s1[i] >='A' && s1[i]<='G' && s1[i] == s2[i]) break;
    }
    day = s1[i] - 'A';//0-6周一到周七
    int hour;
    for(j = i + 1;;j++){
        if((s1[j] == s2[j])&&( isdigit(s1[j]) || (s1[j]>='A'&& s1[j]<='N') ) ) break;
    }
    if(isdigit(s1[j]) ) hour = s1[j] - '0';
    else hour = s1[j] - 'A' + 10;
    int minute;
    for(i = 0;;i++){
        if(s3[i] == s4[i] && isalpha(s3[i]) )break;
    }
    minute = i;
    cout<<week[day];
    printf(" %02d:%02d",hour,minute);
    return 0;
}