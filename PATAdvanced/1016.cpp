#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
struct Person{
    string name;
    int status;
    int month,day,hour,minute;
    int time;
};
int rate[25] = {0};
bool cmp(Person a,Person b){
    return a.name != b.name? a.name < b.name : a.time < b.time;
}

double billFromZero(Person call){
    //day : (10*60 + 10*60 + 20*60....)*day
    double total = rate[24] * 60 * call.day;
    for(int i = 0; i < call.hour ;i++){
        total += rate[i] * 60;
    }
    total += rate[call.hour] * call.minute;
    return total / 100.0;
}


int main(){
    int n;
    for(int i = 0;i < 24;i++){
        scanf("%d",&rate[i]);
        rate[24] += rate[i];//用于天
    }
    scanf("%d",&n);
    vector<Person> data(n);
    for(int i = 0;i < n;i++){
        cin >> data[i].name;
        scanf("%d:%d:%d:%d",&data[i].month,&data[i].day,&data[i].hour,&data[i].minute);
        string temp;
        cin >> temp;
        data[i].status = (temp == "on-line") ? 1 : 0;
        data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
    }
    sort(data.begin(),data.end(),cmp);
    //map插入string后也是按string字典序排
    map<string,vector<Person>> custom;
    //分别插入start end
    for(int i = 1;i < n;i++){
        if(data[i].name == data[i - 1].name && data[i - 1].status == 1 && data[i].status == 0){
            custom[data[i].name].push_back(data[i-1]);
            custom[data[i].name].push_back(data[i]);
        }
    }
    for(auto it : custom){
        vector<Person> temp = it.second;
        cout << it.first;
        printf(" %02d\n",temp[0].month);
        double total = 0.0;
        for(int i = 1;i < temp.size();i += 2){
            double t = billFromZero(temp[i]) - billFromZero(temp[i - 1]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",temp[i-1].day,temp[i-1].hour,temp[i-1].minute,temp[i].day,temp[i].hour,temp[i].minute,temp[i].time - temp[i-1].time,t);
            total += t;
        }
        printf("Total amount: $%.2f\n",total);
    }
    return 0;
}