class Solution {
public:
    /*void comb(int ind, int target, vector<int> &candidates, set<vector<int>> &ans, vector<int>& ds){
        if(target == 0){
            ans.insert(ds);
            return;
        }
        if(ind == candidates.size()){
            if(target == 0){
                ans.insert(ds);
            }
            return;
        }
        if(candidates[ind] <= target){
            ds.push_back(candidates[ind]);
            comb(ind+1, target - candidates[ind], candidates, ans, ds);
            ds.pop_back();
        }
        comb(ind+1, target, candidates, ans, ds);
    }*/
    void comb(int index, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int>& ds){
        if(target == 0){
            ans.push_back(ds);
            return;
        }
        for(int i = index; i<candidates.size(); i++) {
            if(i > index && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) break;
            ds.push_back(candidates[i]);
            comb(i+1, target - candidates[i], candidates, ans, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        //set<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        comb(0, target, candidates, ans, ds);
        //vector<vector<int>> res(ans.begin(), ans.end());
        //return res;
        return ans;
    }
};