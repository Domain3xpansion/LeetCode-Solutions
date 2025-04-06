class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for(int val: nums){
            res = res ^ val;
        }
        for(int i=0; i<=nums.size(); i++){
            res = res ^ i;
        }
        return res;
    }
};