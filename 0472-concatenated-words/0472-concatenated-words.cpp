class Solution {
public:
    bool concatenated(unordered_set<string>& us, string str, unordered_map<string, bool>& memo){
        if(memo.find(str) != memo.end()) 
            return memo[str];
        for(int i=0; i<str.size(); i++){
            string prefix = str.substr(0, i+1);
            string suffix = str.substr(i+1);
            if((us.find(prefix) != us.end() && us.find(suffix) != us.end()) || (us.find(prefix) != us.end() && concatenated(us, suffix, memo)))
                return memo[str] = true;
        }
        return memo[str] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n = words.size();
        vector<string> result;
        unordered_set<string> us(words.begin(), words.end());
        unordered_map<string, bool> memo;

        for(int i=0; i<n; i++){
            if(concatenated(us, words[i], memo))
                result.push_back(words[i]);
        }
        return result;
    }
};