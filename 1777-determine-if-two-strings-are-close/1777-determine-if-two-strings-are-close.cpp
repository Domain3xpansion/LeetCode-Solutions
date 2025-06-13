class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int w1l = word1.size(), w2l = word2.size();
        vector<int> freq_word1(26, 0), freq_word2(26, 0);
        if(w1l != w2l)
            return false;
        for(int i=0; i<w1l; i++){
            freq_word1[word1[i]-'a']++;
            freq_word2[word2[i]-'a']++;
        }
        for(int i=0; i<26; i++){
            if((freq_word1[i] != 0 && freq_word2[i] != 0) || (freq_word1[i] == 0 && freq_word2[i] == 0))
                continue;
            else
                return false;
        }
        sort(freq_word1.begin(), freq_word1.end());
        sort(freq_word2.begin(), freq_word2.end());
        return freq_word1 == freq_word2;
    }
};