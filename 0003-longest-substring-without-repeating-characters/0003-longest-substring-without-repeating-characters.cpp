class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, n=s.size(), maxLen = 0, len=0;
        int freq[256];
        fill(freq, freq + 256, -1);
        while(r<n){
            if(freq[s[r]] != -1){      
                if(freq[s[r]] >= l)     
                    l = freq[s[r]] + 1;
            }
            len = r - l + 1;
            maxLen = max(len, maxLen);
            freq[s[r]] = r;
            r++;
        }
        return maxLen;
    }
};