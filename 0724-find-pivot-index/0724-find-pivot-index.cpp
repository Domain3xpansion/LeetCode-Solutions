class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum = 0, leftsum = 0;
        for(auto &x : nums){
            totalsum += x;
        }
        for(int i=0; i<nums.size(); i++){
            if(leftsum == totalsum - leftsum - nums[i])
                return i;
            else
                leftsum += nums[i];
        }
        return -1;
    }
};