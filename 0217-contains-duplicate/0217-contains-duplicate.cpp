class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> um;
        for(auto &x: nums){
            um[x]++;
            if(um[x] >= 2)
                return true;
        }
        return false;
    }
};