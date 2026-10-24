class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // brute force
        /*int n = nums.size(), minsize = n+1;
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i; j<n; j++){
                sum += nums[j];
                if(sum >= target){
                    minsize = min(minsize, j - i + 1);
                    break;
                }
            }
        }
        return minsize == n + 1 ? 0 : minsize;*/
        
        
        // optimal 
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