#include<iostream>
#include<map>
#include<set>
#include<string>
#include<sstream>
using namespace std;
map<string,set<int>> book[6];
// 任何查询，返回按ID递增排序。结果不唯一（可能没有结果）
int main(){
    int n,m,id;
    cin >> n;
    for(int i = 0;i < n;i++){
        scanf("%d\n",&id);
        string line;
        for(int j = 1;j<=5;j++){
            getline(cin,line);
            if(j == 3){
                istringstream iss(line);
                string temp;    
                while(iss >> temp){
                    book[j][temp].insert(id);
                    // cout << temp << " ";
                }
                // cout << endl;
            }else{
                book[j][line].insert(id);
                // cout << line << endl;
            }
        }
    }
    scanf("%d",&m);
    getchar();
    string s;
    int num;
    for(int i = 0;i < m;i++){
        // scanf("%d: ",&num);
        getline(cin,s);
        // cout << num << ": " << s << "\n";
        cout << s <<endl;
        num = s[0] - '0';
        s = s.substr(3);
        if(book[num].find(s) != book[num].end()){
            // set遍历
            for(auto it = book[num][s].begin();it != book[num][s].end();it++)
                printf("%07d\n",*it);
        }else{
            cout << "Not Found\n";
        }
    }
    return 0;
}