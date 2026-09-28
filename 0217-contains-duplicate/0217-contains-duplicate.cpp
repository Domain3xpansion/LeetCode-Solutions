class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //Approach 1
        /*unordered_map<int, int> um;
        for(auto &x: nums){
            um[x]++;
            if(um[x] >= 2)
                return true;
        }
        return false;*/

        //Approach 2
        unordered_set<int> seen;
        for(auto& x : nums){
            if(seen.count(x))
                return true;
            seen.insert(x);
        }
        return false;
    }
};