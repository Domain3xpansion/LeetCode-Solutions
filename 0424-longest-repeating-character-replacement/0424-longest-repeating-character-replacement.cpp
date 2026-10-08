class Solution {
public:
    int characterReplacement(string s, int k) {
        // Brute force
        /*int n = s.size(), maxLen = 0;
        for(int i=0; i<n; i++){
            int freq_s[26] = {0}, maxFreq = 0;
            for(int j=i; j<n; j++){
                freq_s[s[j]-'A']++;
                maxFreq = max(maxFreq, freq_s[s[j]-'A']);
                int chars_to_be_removed = (j-i+1) - maxFreq;
                if(chars_to_be_removed <= k)
                    maxLen = max(maxLen, j-i+1);
                else
                    break;
            }
        }
        return maxLen;*/
        int i=0, j=0, n = s.size(), maxfreq = 0, maxLen = 0;
        int freq_s[26] = {0};
        while(j<n){
            freq_s[s[j]-'A']++;
            maxfreq = max(maxfreq, freq_s[s[j]-'A']);
            int charstoberemoved = (j-i+1) - maxfreq;
            while(charstoberemoved > k){
                freq_s[s[i] - 'A']--;
                i++;
                charstoberemoved = (j - i + 1) - maxfreq;
            }
            if(charstoberemoved <= k){
                maxLen = max(maxLen, j-i+1);
                j++;
            }
        }
        return maxLen;
    }
};