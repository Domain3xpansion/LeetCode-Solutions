class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> presence;
        for(auto &num : nums){
            if(presence.count(num))
                return num;
            presence.insert(num);
        }
        return -1;
    }
};