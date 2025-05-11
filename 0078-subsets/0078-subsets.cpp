class Solution {
public:
    void subsetr(int index, vector<int> vec, vector<vector<int>>& ans, vector<int>& ds){
        if(index == vec.size()){
            ans.push_back(ds);
            return;
        }
        subsetr(index+1, vec, ans, ds);    // not pick element
        ds.push_back(vec[index]);
        subsetr(index+1, vec, ans, ds);    // pick element 
        ds.pop_back();
    }  

    vector<vector<int>> subsets(vector<int>& nums) {
        /*vector<vector<int>> outer = {{}};
        for(int num : nums){
            int n = outer.size();
            for(int i = 0; i < n; ++i){
                vector<int> internal = outer[i];
                internal.push_back(num);
                outer.push_back(internal);
            }
        }
        return outer;
        */
        vector<vector<int>> ans;
        vector<int> ds;
        subsetr(0, nums, ans, ds);
        return ans;
    }
};