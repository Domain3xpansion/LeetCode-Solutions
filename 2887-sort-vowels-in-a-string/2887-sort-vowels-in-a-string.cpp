class Solution {
public:
    string sortVowels(string s) {
        /*int n = s.size(), j;
        int pair = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        for(int i=0; i<n; i++){
            if(vowels.find(s[i]) != vowels.end()){
                if(pair == 0){
                    j = i;
                    pair += 1;
                }
                if(pair == 1){
                    if(s[j]>s[i])
                        swap(s[i], s[j]);
                    j = i;
                }
            }
        }
        return s;*/

        vector<char> place;
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
        return s;
    }
};