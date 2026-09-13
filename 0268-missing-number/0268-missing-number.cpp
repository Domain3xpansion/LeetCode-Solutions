class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /*int res = 0;
        for(int val: nums){
            res = res ^ val;
        }
        for(int i=0; i<=nums.size(); i++){
            res = res ^ i;
        }
        return res;*/

        // Brute force
        /*for(int i=0; i<=nums.size(); i++){
            int flag = 0;
            for(int j=0; j<nums.size(); j++){
                if(i == nums[j]){
                    flag = 1;
                    break;
                }
            }
            if(flag == 0)
                return i;
        }
        return -1;*/

        // Better
        unordered_map<int, int> hashmap;
        for(int x: nums){
            hashmap[x]++;
        }
        for(int i=0; i<=nums.size(); i++){
            if(hashmap[i] == 0)
                return i;
        }
        return -1;
    }
};