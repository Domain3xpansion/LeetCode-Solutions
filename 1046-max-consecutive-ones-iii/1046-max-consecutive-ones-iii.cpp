class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        /*int n = nums.size(), maxlength = INT_MIN;
        for(int i=0; i<n; i++){
            int count_zeroes = 0;
            for(int j=i; j<n; j++){
                if(nums[j] == 0)
                    count_zeroes++;
                if(count_zeroes <= k)
                    maxlength = max(maxlength, j - i + 1);
                else
                    break;
            }
        }  
        return maxlength;*/

        int i=0, j=0, n=nums.size(), zeroes = 0, maxlength = INT_MIN, length = 0;
        while(j<n){
            if(nums[j] == 0)
                zeroes++;
            if(zeroes > k){
                while(nums[i] != 0){
                    i++;
                }
                while(zeroes > k){
                    i++;
                    zeroes--;
                }
            }
            length = j - i + 1;
            maxlength = max(maxlength, length);
            j++;
        }
        return maxlength;
    }
};