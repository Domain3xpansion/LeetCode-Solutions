class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.size(); i++) {
            s[i] = std::tolower(s[i]);
        }
        return s;
    }
};