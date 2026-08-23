class Solution {
public:
    bool isIsomorphic(string s, string t) {
        /*map<char, int> s_freq;
        map<char, int> t_freq;
        for(char c : s){
            s_freq[c]++;
        }
        for(char c : t){
            t_freq[c]++;
        }
        map<int, int> freq1;
        map<int, int> freq2;
        for(auto &[key, value] : s_freq){
            freq1[value]++;
        }
        for(auto &[key, value] : t_freq){
            freq2[value]++;
        }
        return freq1 == freq2;*/

        map<char, char> onetoone;
        for(int i = 0; i < s.size(); i++){
            char c1 = s[i];
            char c2 = t[i]; 
            if(!onetoone.count(c1)){
                for(auto& [key, val]:onetoone){
                    if(val == c2)
                        return false;
                }
                onetoone.insert({c1, c2});
            }
            else{
                if(onetoone[c1] != c2)
                    return false;
            }
        }
        return true;
    }
};