class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0);
        vector<string> res;
        for(string &w : words2){
            vector<int> freq(26, 0);
            for(char c : w){
                freq[c - 'a']++;
            }
            for(int i=0; i<26; i++){
                if(freq[i] > maxFreq[i])
                    maxFreq[i] = freq[i];
            }
        }
        for(string& w : words1) {
            vector<int> freq(26, 0);
            for(char c : w){
                freq[c - 'a']++;
            }
            bool Universal = true;
            for(int i=0; i<26; i++) {
                if(freq[i] < maxFreq[i]){
                    Universal = false;
                    break;
                }
            }
            if(Universal)
                res.push_back(w);
        }
        return res;
    }
};