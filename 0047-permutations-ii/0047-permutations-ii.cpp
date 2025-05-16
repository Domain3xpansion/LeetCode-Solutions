class Solution {
public:
    //Approach 1 - using the frequency of all numbers present in the given vector(using unordered_map)
    void permuteUniquehelper(vector<int>& ds, unordered_map<int, int> &um, vector<vector<int>> &result, int n){
        if(ds.size() == n) { 
            result.push_back(ds);   //O(n) time
            return;
        }
        for(auto& [num, count] : um){
            if(count == 0)
                continue;
            ds.push_back(num);
            um[num]--;

            permuteUniquehelper(ds, um, result, n);

            ds.pop_back();
            um[num]++;
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums){
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> temp;   // will store the each permutation
        unordered_map<int, int> um;    // to store frequency of every number present in nums vector
        for(auto& num : nums){     // count the occurrences of each number
            um[num]++;
        }
        permuteUniquehelper(temp, um, result, n);
        return result;
    }
};