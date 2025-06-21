class Solution {
public:
    string sortVowels(string s) {
        /*vector<char> place;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.size(), j=0;
        for(int i=0; i<n; i++){
            if(vowels.find(s[i]) != vowels.end())
                place.push_back(s[i]);
        }
        sort(place.begin(), place.end());
        for(int i=0; i<n; i++){
            if(vowels.find(s[i]) != vowels.end()){
                s[i] = place[j]; 
                j++;
            }
        }
        return s;*/

        unordered_map<char, int> um;
        int j = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(char ch: s){
            if(vowels.find(ch) != vowels.end())
                um[ch]++;
        }
        string ordered = "AEIOUaeiou";
        for(int i=0; i<s.size(); i++){
            if(vowels.find(s[i]) != vowels.end()){
                while(um[ordered[j]] == 0){
                    j++;
                }
                s[i] = ordered[j];
                um[ordered[j]]--;
            }
        }
        return s;
    }
};