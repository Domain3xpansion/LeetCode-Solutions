class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> a_nums = nums; 
        vector<int> d_nums = nums; 
        std::sort(a_nums.begin(), a_nums.end()); 
        std::sort(d_nums.begin(), d_nums.end(), std::greater<int>()); 
        if(a_nums == nums || d_nums == nums){
            return true;
        }
        return false;
    }
};