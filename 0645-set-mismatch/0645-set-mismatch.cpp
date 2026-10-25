class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size(), repeat = -1, missing = -1;
        for(int i=1; i<=n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(nums[j] == i)
                    count++;
            }
            if(count == 2)
                repeat = i;
            if(count == 0)
                missing = i;
        }
        return {repeat, missing};
    }
};