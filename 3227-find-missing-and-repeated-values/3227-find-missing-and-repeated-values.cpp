class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int rows = grid.size();
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
        return {repeat, missing};
    }
};