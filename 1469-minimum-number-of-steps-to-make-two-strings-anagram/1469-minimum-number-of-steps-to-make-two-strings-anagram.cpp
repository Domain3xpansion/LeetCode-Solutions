class Solution {
public:
    int minSteps(string s, string t) {
        /*int n = s.size(), result = 0;
        int freq_s[26] = {0}, freq_t[26] = {0};
        for(int i=0; i<n; i++){
            freq_s[s[i]-'a']++;
            freq_t[t[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if(freq_s[i]>freq_t[i])
                result += freq_s[i]-freq_t[i];
        }
        return result;*/
        int n = s.size(), result = 0;
        int freq[26] = {0};
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(int i=0; i<26; i++){
            if(freq[i]>0)
                result += freq[i];
        }
        return result;
    }
};