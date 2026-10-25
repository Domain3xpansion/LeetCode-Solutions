class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        // approach 1
        /*int n = nums.size(), repeat = -1, missing = -1;
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
        return {repeat, missing}; */

        // approach 2
        int n = nums.size(), repeat = -1, missing = -1;
        int freq_nums[n + 1];
        fill(freq_nums, freq_nums + n + 1, 0);
        for(int i=0; i<n; i++){
            freq_nums[nums[i]]++;
        }
        for(int i=1; i<n+1; i++){
            if(freq_nums[i] == 2)
                repeat = i;
            if(freq_nums[i] == 0)
                missing = i;
        }
        return {repeat, missing};
    }
};