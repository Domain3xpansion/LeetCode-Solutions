class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size(), l = 0, r = 0, prod = 1, count = 0;
        while(r<n){
            prod = prod * nums[r];
            while(prod >= k){
                prod = prod / nums[l];
                l++;
            }
            if(prod < k)
                count += r - l + 1;
            r++;
        }
        return count;
    }
};