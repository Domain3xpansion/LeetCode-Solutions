class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        vector<int> vec;
        int n = nums.size();
        int min = (n/3) + 1;
        for(int x : nums){
            hashmap[x]++;
            if(hashmap[x] == min)
                vec.push_back(x);
        }
        return vec;
    }
};