class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //Same code as lower_bound of a number 'x'
        int low = 0, high = nums.size() - 1;
        int ans = nums.size();
        while(low <= high){
            long long mid = low + (high - low) / 2;
            if(nums[mid] >= target){
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return ans;
    }
};