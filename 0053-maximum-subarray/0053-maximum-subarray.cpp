class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Optimal approach using Kadanes algo
        // For brute and better approaches, refer my Github
        int sum = 0, maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum > maxi)
                maxi = sum;
            if(sum < 0)
                sum = 0;
        }
        return maxi;
    }
};