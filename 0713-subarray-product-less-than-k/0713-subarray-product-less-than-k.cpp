class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // brute force
        int n = nums.size(), count = 0;
        for(int i = 0 ; i < n; i++){
            int prod = 1;
            for(int j = i; j < n; j++){
                prod *= nums[j];
                if(prod >= k){
                    prod = prod / nums[i];
                    break;
                }
                else{
                    count++;
                }
            }
        }
        return count;
        
        //optimal
        /*if (k <= 1) return 0;
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
        return count;*/
    }
};