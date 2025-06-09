class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int n = nums.size();
        int min = (n/2) + 1;
        for(int x : nums){
            hashmap[x]++;
            if(hashmap[x] == min)
                return x;
        }
        return -1;
    }
};