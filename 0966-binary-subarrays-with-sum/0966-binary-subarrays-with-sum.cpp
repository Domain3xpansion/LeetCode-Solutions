class Solution {
public:
    int binsubarrwithsum(vector<int>& nums, int goal){
        if(goal<0)
            return 0;
        int l=0, r=0, sum = 0, count = 0;
        while(r<nums.size()){
            if(sum<=goal)
                sum += nums[r];
            while(sum>goal){
                sum = sum - nums[l];
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return binsubarrwithsum(nums, goal) - binsubarrwithsum(nums, goal-1);
    }
};