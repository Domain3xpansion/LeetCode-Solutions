class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size(), l = 0, r = 0, minsize = n + 1, sum = 0;
        while(r<n){
            sum = sum + nums[r];
            while(sum >= target){
                minsize = min(minsize, r - l + 1);
                sum = sum - nums[l];
                l++;
            }
            r++;
        }
        return minsize == n + 1 ? 0 : minsize;
    }
};