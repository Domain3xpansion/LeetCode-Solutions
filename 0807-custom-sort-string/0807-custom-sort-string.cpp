class Solution {
public:
    string customSortString(string order, string s) {
        /*string result;
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
        return result;*/

        vector<int> index(26, -1);
        for(int i = 0; i < order.length(); i++){
            char ch = order[i];
            index[ch - 'a'] = i;
        }
        auto comparator = [&index](char &ch1, char &ch2){
            return index[ch1-'a'] < index[ch2-'a'];
        };
        sort(s.begin(), s.end(), comparator);
        return s;
    }
};