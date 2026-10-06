class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //Brute force
        /*if(s1.empty()) 
            return true;
        if(s1.size() > s2.size()) 
            return false;
        int l=0, r=s1.size()-1, n=s2.size();
        int freq_s1[26] = {0};
        for(char c:s1){
            freq_s1[c-'a']++;
        }
        while(r<n){
            int freq_s2[26] = {0};
            bool perm = true;
            for(int i=l; i<=r; i++){
                freq_s2[s2[i] - 'a']++;
            }
            for(int i=0; i<26; i++){
                if(freq_s1[i] != freq_s2[i]){
                    perm = false;
                    break;
                }
            }
            if(perm)
                return true;
            l++;
            r++;
        }
        return false;*/

        if(s1.empty()) 
            return true;
        if(s1.size() > s2.size()) 
            return false;
        int l=0, r=s1.size()-1, n=s2.size();
        int freq_s1[26] = {0}, freq_s2[26] = {0};
        for(char c:s1){
            freq_s1[c-'a']++;
        }
        for(int i = 0; i <= r; i++){
            freq_s2[s2[i]-'a']++;
        }
        while(r<n){
            bool perm = true;
            for(int i=0; i<26; i++){
                if(freq_s1[i] != freq_s2[i]){
                    perm = false;
                    break;
                }
            }
            if(perm)
                return true;
            
            freq_s2[s2[l]-'a']--;
            l++;
            r++;
            if(r<n)
                freq_s2[s2[r]-'a']++;
        }
        return false;
    }
};