class Solution {
public:
    bool isVowel(char ch){
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }

    int beautifulSubstrings(string s, int k){
        int n = s.size(), beautiful = 0;
        for(int i=0; i<n; i++){
            int v_count = 0, c_count = 0;
            for(int j=i; j<n; j++){
                if(isVowel(s[j]))
                    v_count++;
                else
                    c_count++;
                if(v_count == c_count && (v_count * c_count) % k == 0)
                    beautiful++;
            }
        }
        return beautiful;
    }
};