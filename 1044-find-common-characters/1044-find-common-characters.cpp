class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> freq(26, INT_MAX);
        for(const string& word : words){
            vector<int> temp(26, 0);
            for(char c : word){
                temp[c-'a']++;
            }
            for(int i=0; i<26; i++){
                freq[i] = min(freq[i], temp[i]);
            }
        }
        vector<string> result;
        for(int i=0; i<26; i++){
            for(int count=0; count<freq[i]; count++){
                result.push_back(string(1, 'a'+i));
            }
        }
        return result;
    }
};