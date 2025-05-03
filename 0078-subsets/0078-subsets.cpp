class Solution {
public:
    vector<vector<int>> helper(vector<int> vec, vector<int> current, vector<vector<int>>& result){
        if(vec.empty()){
            result.push_back(current);
            return result;
        }
        int first = vec[0];
        vector<int> rest(vec.begin() + 1, vec.end());
        helper(rest, current, result);
        current.push_back(first);
        helper(rest, current, result);
        return result;
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
        vector<vector<int>> result;
        vector<int> current;
        return helper(nums, current, result);
    }
};