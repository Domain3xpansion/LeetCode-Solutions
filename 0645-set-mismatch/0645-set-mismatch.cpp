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
        /*int n = nums.size(), repeat = -1, missing = -1;
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
        return {repeat, missing};*/

        /*
        a = repeating number
        b = missing number
        Snums - S = (1 + 2 + 2 + 4) - (1 + 2 + 3 + 4) = 9 - 10 = -1
            (If you cancel out the numbers)             2 - 3 = -1   Got the value of a-b      equation 1
        Snums^2 - S^2 = (1^2 + 2^2 + 2^2 + 4^2) - (1^2 + 2^2 + 3^2 + 4^2) = 25 - 30 = -5
            (If you cancel out the numbers)             2^2 - 3^2 = -5  (a^ - b^2 = (a-b)(a+b) formula)       equation 2
        */
        int n = nums.size();
        long long S = 1LL * n * (n + 1) / 2;
        long long S_squared = 1LL * n * (n + 1) * (2LL * n + 1) / 6, Snums = 0, Snums_squared = 0;
        for(int i=0; i<n; i++){
            Snums += nums[i];
            Snums_squared += nums[i] * nums[i];
        }
        long long value1 = Snums - S;      // a-b
        long long value2 = Snums_squared - S_squared;    // (a-b)(a+b)
        long long aplusb = value2/value1;
        long long repeat = (aplusb + value1)/2;
        long long missing = repeat - value1;
        return {(int)repeat, (int)missing};
    }
};