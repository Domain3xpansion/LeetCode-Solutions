class Solution {
public:
    void permuteUniquehelper(vector<int>& ds, unordered_map<int, int> &um, vector<vector<int>> &result, int n){
        if(ds.size() == n) { 
            result.push_back(ds);
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
        unordered_map<int, int> um;
        for(auto& num : nums){     // count the occurrences of each number
            um[num]++;
        }
        vector<int> temp;
        vector<vector<int>> result;
        permuteUniquehelper(temp, um, result, n);
        return result;
    }
};