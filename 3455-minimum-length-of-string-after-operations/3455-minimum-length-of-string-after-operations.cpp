class Solution {
public:
    int minimumLength(string s) {
        /*vector<int> freq(26, 0);
        int result = 0;
        for(char &ch:s){
            freq[ch-'a']++;
        }
        for(int i=0; i<26; i++){
            if(freq[i] == 0)
                continue;
            if(freq[i] % 2 == 0)
                result += 2;
            else
                result += 1;
        }
        return result;*/
        int count = 0;
        vector<int> freq(26, 0);
        for(char &ch:s){
            freq[ch-'a']++;
            if(freq[ch-'a'] == 3){
                freq[ch-'a'] -= 2;
                count += 2;
            }
        }
        return s.size() - count;
    }
};