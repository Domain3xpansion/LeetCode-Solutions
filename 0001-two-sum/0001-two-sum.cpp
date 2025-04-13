class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for(int i=0; i<nums.size(); i++){
            int y = target - nums[i];
            if(hashtable.find(y) != hashtable.end())
                return {hashtable[y], i};
            else
                hashtable[nums[i]] = i;
        }
        return {};
    }
};