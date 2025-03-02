class Solution {
public:
    int maxPower(string s) {
        int maxPower = 0; 
        int currentPower = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                currentPower++; 
            } else {
                maxPower = max(maxPower, currentPower);
                currentPower = 1; 
            }
        }
        maxPower = max(maxPower, currentPower);
        return maxPower;
    }
};