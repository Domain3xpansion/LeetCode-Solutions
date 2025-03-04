class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int sum = 0, subarrsum, start;
        for(int i=0; i<nums.size(); i++){
            subarrsum = 0;
            start = std::max(0, i-nums[i]);
            for(int j=start; j<=i; j++){
                subarrsum += nums[j];
            }
            sum += subarrsum;
        }
        return sum; 
    }
};