class Solution {
public:
    int binsubarrwithsum(vector<int>& nums, int goal){
        // optimal approach (same as Binary Subarrays With Sum problem)
        int l=0, r=0, sum = 0, count = 0;
        while(r<nums.size()){
            if(sum<=goal)
                sum += nums[r] % 2;
            while(sum>goal){
                sum = sum - nums[l] % 2;
                l++;
            }
            count += (r-l+1);
            r++;
        }
        return count;
    }


    int numberOfSubarrays(vector<int>& nums, int k) {
        // Brute force
        /*int n = nums.size();
        int nice = 0;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=i; j<n; j++){
                if(nums[j]%2 == 1)
                    count++;
                if (count > k)
                    break;
                if (count == k)
                    nice++;
            }
        }
        return nice;*/

        return binsubarrwithsum(nums, k) - binsubarrwithsum(nums, k-1);
    }
};