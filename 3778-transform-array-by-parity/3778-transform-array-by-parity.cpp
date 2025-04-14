class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int i  = 0, j = nums.size() - 1;
        for(auto &val : nums){
            if(val%2==0)
                val = 0;
            else
                val = 1;
        }
        while(i<j){
            if(nums[i]==1 && nums[j]==0){
                swap(nums[i], nums[j]);
                i++;
                j--;
            }else if(nums[i]==0)
               i++;
            else
                j--;
        }
        return nums;
    }
};