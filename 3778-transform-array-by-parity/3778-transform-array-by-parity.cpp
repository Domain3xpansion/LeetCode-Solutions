class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        for(auto &val : nums){
            if(val%2==0)
                val = 0;
            else
                val = 1;
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};