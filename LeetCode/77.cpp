class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        if(n<=0 || k<=0) return res;
        vector<int> track;
        backtrack(n,k,1,track);
        // dfs(n,k,1,track);
        return res;
    }   

    void backtrack(int n,int k,int start,vector<int>& track){
        // 剪枝
        // track 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 track
        if(track.size() + (n - start + 1) < k) return;
        if(k == track.size()){
            res.push_back(track);
            return;
        }

        for(int i = start;i<=n;i++){
            track.push_back(i);
            backtrack(n,k,i+1,track);
            track.pop_back();
        }
    }

    // 选或不选 二叉树
    void dfs(int n,int k,int i,vector<int>& track){
        if(track.size() == k){
            res.push_back(track);
            return;
        }
        if(i == n + 1) return;
        dfs(n,k,i+1,track);

        track.push_back(i);
        dfs(n,k,i+1,track);
        track.pop_back();
    }
};