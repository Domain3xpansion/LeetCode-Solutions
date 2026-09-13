class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /*int res = 0;
        for(int val: nums)
            res = res ^ val;
        return res;*/

        // Better approach
        unordered_map<int, int> hashmap;
        for(int x: nums){
            hashmap[x]++;
        }
        for(auto val : hashmap){
            if(val.second == 1)
                return val.first;
        }
        return -1;
    }
};