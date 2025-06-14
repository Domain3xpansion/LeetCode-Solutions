class Solution {
public:
    bool detectCapitalUse(string word) {
        int countcapital = 0;
        for(char &ch : word){
            if(isupper(ch))
                countcapital++;
        }
        if(countcapital == word.size() || countcapital == 0 || countcapital == 1 && isupper(word[0]))
            return true;
        return false;
    }
};