class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size())
            return false;
        int noofodd = 0;
        unordered_map<char, int> um;
        for(char c : s){
            um[c]++;
        }
        for(auto x : um){
            if(x.second % 2 == 1)
                noofodd++;
        }
        if(noofodd <= k)
            return true;
        return false;
    }
};