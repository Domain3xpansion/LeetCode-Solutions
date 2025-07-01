class Solution {
public:
    string customSortString(string order, string s) {
        string result;
        unordered_map<char, int> um;
        for(char &i : s){
            um[i]++;
        }
        for(char &i : order){
            while(um[i] != 0){
                result.push_back(i);
                um[i]--;
            }
        }
        for(char &i : s){
            if(um[i] != 0){
                result.push_back(i);
            }
        }
        return result;
    }
};