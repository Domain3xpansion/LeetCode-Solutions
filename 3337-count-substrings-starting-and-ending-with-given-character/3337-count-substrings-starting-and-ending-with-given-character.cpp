class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long result = 0, past_occ = 0;
        for(auto &i : s){
            if(i == c){
                result += past_occ + 1;
                past_occ++;
            }
        }
        return result;
    }
};