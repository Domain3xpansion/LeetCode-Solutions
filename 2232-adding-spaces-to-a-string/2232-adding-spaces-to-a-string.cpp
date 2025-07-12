class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        /*unordered_set<int> spacePositions(spaces.begin(), spaces.end());
        string result;
        for(int i = 0; i < s.size(); i++){
            if(spacePositions.find(i) != spacePositions.end())
                result.push_back(' ');
            result.push_back(s[i]);
        }
        return result;*/
        string result;
        int j=0;
        for(int i = 0; i < s.size(); i++){
            if(j<spaces.size() && i == spaces[j]){
                result.push_back(' ');
                j++;
            }
            result.push_back(s[i]);
        }
        return result;

    }
};