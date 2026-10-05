class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int l = 0, r = p.size() - 1, n = s.size();;
        int freq_p[26] = {0};
        for(char c : p){
            freq_p[c - 'a']++;
        }
        vector<int> startindices;
        while(r<n){
            int freq_s[26] = {0};
            for(int i = l; i <= r; i++){
                freq_s[s[i] - 'a']++;
            }
            bool same = true;
            for(int i = 0; i < 26; i++){
                if (freq_s[i] != freq_p[i]){
                    same = false;
                    break;
                }
            }
            if(same)
                startindices.push_back(l);
            l++;
            r++;
        }
        return startindices;
    }
};