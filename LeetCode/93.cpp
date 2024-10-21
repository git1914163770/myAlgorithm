// 93. 复原 IP 地址

class Solution {
public:
    vector<string> res;

    // pointNum: 添加逗点的数量 也是递归的深度-1
    void trace(string& s,int start,int pointNum){
        if(pointNum == 3){
            if(isValid(s,start,s.size()-1)){
                res.push_back(s);
            }
            return;
        }
        for(int i = start;i < s.size();i++){
            if(isValid(s,start,i)){
                s.insert(s.begin() + i + 1,'.');
                pointNum++;
                trace(s,i+2,pointNum);
                pointNum--;
                s.erase(s.begin() + i +1);
            }else break;
        }
    }

    bool isValid(const string& s,int start,int end){
        if(start > end) return false;
        if(s[start] == '0' && start != end){
            return false;
        }
        int num = 0;
        for(int i = start;i <= end;i++){
            if(s[i] > '9' || s[i] < '0'){
                return false;
            }
            num = num * 10 + (s[i] - '0');
            if(num > 255) return false;
        }
        return true;
    }

    vector<string> restoreIpAddresses(string s) {
        res.clear();
        if(s.size() > 12) return res;
        trace(s,0,0);
        return res;
    }
};