class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> vec;
        int sum = 0;
        for(int x: nums){
            sum += x;
            vec.push_back(sum);
        }
        return vec;
    }
};