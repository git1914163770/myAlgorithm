#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
struct People{
    int id;
    string name;
    int grade;
};
bool cmp1(People p1,People p2){
    return p1.id < p2.id;
}
bool cmp2(People p1,People p2){
    if(p1.name != p2.name) return p1.name < p2.name;
    else return p1.id < p2.id;
}
bool cmp3(People p1,People p2){
    if(p1.grade != p2.grade) return p1.grade < p2.grade;
    else return p1.id < p2.id;
}

// int c;
// bool cmp1(NODE a, NODE b) {
//     if(c == 1) {
//         return a.no < b.no;
//     } else if(c == 2) {
//         if(strcmp(a.name, b.name) == 0) return a.no < b.no;
//         return strcmp(a.name, b.name) <= 0;
//     } else {
//         if(a.score == b.score) return a.no < b.no;
//         return a.score <= b.score;
//     }
// }

int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    // cin>>n>>c;
    vector<People> people(n);
    for(int i = 0;i<n;i++){
        scanf("%d",&people[i].id);
        cin>>people[i].name;
        scanf("%d",&people[i].grade);
    }
    switch(c){
        case 1:
            sort(people.begin(),people.end(),cmp1);
            break;
        case 2:
            sort(people.begin(),people.end(),cmp2);
            break;
        case 3:
            sort(people.begin(),people.end(),cmp3);
            break;          
        default:
            break;
    }
    for(int i = 0;i<n;i++){
        printf("%06d ",people[i].id);
        cout<<people[i].name;
        printf(" %d\n",people[i].grade);
    }
    return 0;
}