class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max = 0;
        for(auto val: nums){
            if(val == 1)
                count++;
            else{
                if(count>max){
                    max = count;
                }
                count = 0;
            }
        }
        if(count>max)
            max = count;
        return max;
    }
};