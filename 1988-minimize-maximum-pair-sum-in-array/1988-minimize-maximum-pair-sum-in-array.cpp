class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, minimizedmaxsum = INT_MIN;
        std::sort(nums.begin(), nums.end());     
        while(i<j){     
            if(nums[i] + nums[j] >= minimizedmaxsum){
                minimizedmaxsum = nums[i] + nums[j];
            }
            i++;
            j--;
        }
        return minimizedmaxsum;
    }
};