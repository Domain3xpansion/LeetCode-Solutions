class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        std::unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        int uniqueSum = 0;
        for (const auto& pair : count) {
            if (pair.second == 1) {
                uniqueSum += pair.first;
            }
        }
        return uniqueSum;
    }
};