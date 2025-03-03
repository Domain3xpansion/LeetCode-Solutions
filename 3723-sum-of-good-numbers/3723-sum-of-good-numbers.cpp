class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum = 0;
        for(int i=0; i<=nums.size()-1; i++){
            if((i-k<0) && (i+k>nums.size()-1)){
                sum += nums[i];
            }
            else if(i-k<0){
                if(nums[i]>nums[i+k]){
                    sum += nums[i];
                }
            }
            else if(i+k>nums.size()-1){
                if(nums[i]>nums[i-k]){
                    sum += nums[i];
                }
            }
            else if((nums[i]>nums[i-k]) && (nums[i]>nums[i+k])){
                sum += nums[i];
            }
        }
        return sum;
    }
};