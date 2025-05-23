class Solution {
public:
    void subsets2(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
        if(ind == nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        subsets2(ind+1, nums, ds, ans);    // pick element 
        ds.pop_back();
        while(ind+1 < nums.size() && nums[ind] == nums[ind+1]) ind++;
        subsets2(ind+1, nums, ds, ans);    // not pick element
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        subsets2(0, nums, ds, ans);
        return ans;
    }
};