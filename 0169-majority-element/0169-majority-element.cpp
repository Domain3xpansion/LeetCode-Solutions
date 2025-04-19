class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        for(int x : nums){
            hashmap[x]++;
        }
        for(auto pair:hashmap){
            if(pair.second > (nums.size()/2))
                return pair.first;
        }
        return -1;
    }
};