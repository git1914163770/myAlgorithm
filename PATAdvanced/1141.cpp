#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

struct node{
    string name;
    int score;
    int num;
};

bool cmp(node n1,node n2){
    if(n1.score != n2.score) return n1.score > n2.score;
    else if(n1.num != n2.num) return n1.num < n2.num;
    else return n1.name < n2.name;
}

// 乙1085
int main(){
    unordered_map<string,double> mp;
    unordered_map<string,int> m2;// 考生人数
    vector<node> res;
    int n;
    cin >> n;
    string id,school;
    int score;
    for(int i = 0;i<n;i++){
        cin >> id >> score >> school;
        for(int i = 0;i<school.size();i++){
            school[i] = tolower(school[i]);
        }
        if(id[0] == 'A'){
            mp[school] += score;
        }else if(id[0] == 'B'){
            mp[school] += score / 1.5;
        }else if(id[0] == 'T'){
            mp[school] += score * 1.5;
        }
        m2[school] ++;
    }
    node n2;
    for(auto it = mp.begin();it!=mp.end();it++){

        n2.name = it->first;
        n2.score = int(it->second);
        n2.num = m2[it->first];
        res.push_back(n2);
    }
    sort(res.begin(),res.end(),cmp);
    int index = 1;
    cout << res.size()<<endl;
    for(int i = 0;i<res.size();i++){
        if(i!=0 && res[i].score == res[i-1].score){
            // cout << index << res[i].name << res[i].score << res[i].num << endl;
        }else{            
            index = i+1;
        }
        printf("%d %s %d %d\n",index,res[i].name.c_str(),res[i].score,res[i].num);
    }
    // 另一种方法
    // int rank = 0, pres = -1;
    // printf("%d\n", (int)ans.size());
    // for (int i = 0; i < ans.size(); i++) {
    //     if (pres != ans[i].tws) rank = i + 1;
    //     pres = ans[i].tws;
    //     printf("%d ", rank);
    //     cout << ans[i].school;
    //     printf(" %d %d\n", ans[i].tws, ans[i].ns);
    // }
    return 0;
}