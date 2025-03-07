class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int maxSoFar = -1;
        for (int i = arr.size() - 1; i >= 0; --i) {
            int currentValue = arr[i]; 
            arr[i] = maxSoFar; 
            maxSoFar = std::max(maxSoFar, currentValue); 
        }
        return arr;
    }
};