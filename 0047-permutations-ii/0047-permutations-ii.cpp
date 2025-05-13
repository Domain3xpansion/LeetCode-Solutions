class Solution {
public:
    void permutations(vector<int> vec, vector<int> freq, set<vector<int>> &ans, vector<int> &ds){
        if(ds.size() == vec.size()){
            ans.insert(ds);
            return;
        }
        for(int i=0; i<vec.size(); i++){
            if(!freq[i]){
                ds.push_back(vec[i]);
                freq[i] = 1;
                permutations(vec, freq, ans, ds);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> ds, freq(nums.size(), 0);
        set<vector<int>> ans;
        permutations(nums, freq, ans, ds);
        vector<vector<int>> res(ans.begin(), ans.end());
        return res;
    }
};