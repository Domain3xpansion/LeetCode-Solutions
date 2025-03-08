class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        std::unordered_map<int, int> countMap;
    
    // Count occurrences of each number
    for (int num : nums) {
        if (countMap.find(num) != countMap.end()) {
            countMap[num]++;
        } else {
            countMap[num] = 1;
        }
    }
    
    int result = 0;
    
    // Calculate XOR of numbers that appear twice
    for (auto& pair : countMap) {
        if (pair.second == 2) {
            result ^= pair.first;
        }
    }
    
    return result;
    }
};