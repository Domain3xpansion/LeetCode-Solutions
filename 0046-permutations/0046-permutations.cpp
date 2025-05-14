class Solution {
public:
    void permutations(vector<int> vec, vector<int> &freq, vector<vector<int>> &ans, vector<int> &ds){
        if(ds.size() == vec.size()){
            ans.push_back(ds);
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
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> freq(n, 0);
        permutations(nums, freq, ans, ds);
        return ans;
    }
};