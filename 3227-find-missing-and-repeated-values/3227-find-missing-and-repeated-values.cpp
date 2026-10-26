class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // approach 1
        /*int rows = grid.size();
        vector<int> nums;
        for(int p = 0; p < rows * rows; p++){
            int i = p / rows;  // row = 1
            int j = p % rows;  // col = 1
            nums.push_back(grid[i][j]);
        }
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
        return {repeat, missing};*/

        //approach 2
        int rows = grid.size();
        vector<int> nums;
        for(int p = 0; p < rows * rows; p++){
            int i = p / rows;  // row = 1
            int j = p % rows;  // col = 1
            nums.push_back(grid[i][j]);
        }
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