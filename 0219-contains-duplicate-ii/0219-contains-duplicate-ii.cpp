class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /*map<int, int> m;
        for(int i=0; i<nums.size(); i++){
            if(m.find(nums[i]) != m.end()){
                if(abs(i-m[nums[i]]) <= k)
                    return true;
            }
            m[nums[i]] = i;
        }
        return false;*/

        unordered_set<int> seen;
        int i=0, j=0;
        while(j<nums.size()){
            while(j-i <= k && j < nums.size()){    // same as abs(i-j) <= k
                if(seen.count(nums[j]))
                    return true;
                seen.insert(nums[j]);
                j++;
            }
            seen.erase(nums[i]);
            i++;
        }
        return false;
    }
};