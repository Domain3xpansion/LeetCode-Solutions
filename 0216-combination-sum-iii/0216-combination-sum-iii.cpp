class Solution {
public:
    void comb3(int index, int n, int k, vector<vector<int>>& ans, vector<int>& ds){
        if(n==0 && k==0){
            ans.push_back(ds);
            return;
        }
        if(n==0 || k == 0) return;
        int loop = (n < 9) ? n : 9;
        for(int i=index+1; i<=loop; i++){
            ds.push_back(i);
            comb3(i, n-i, k-1, ans, ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        comb3(0, n, k, ans, ds);
        return ans;
    }
};