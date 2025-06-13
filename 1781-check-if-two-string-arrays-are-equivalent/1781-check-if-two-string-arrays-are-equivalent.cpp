class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        /*string res1 = "", res2 = "";
        for(int i=0; i<word1.size(); i++){
            res1 = res1 + word1[i];
        }
        for(int i=0; i<word2.size(); i++){
            res2 = res2 + word2[i];
        }
        if(res1 == res2)
            return true;
        return false;*/

        int m = word1.size(), n = word2.size();
        int w1i = 0, w2i = 0;
        int i=0, j=0;
        while(w1i<m && w2i<n){
            if(word1[w1i][i] != word2[w2i][j])
                return false;
            i++;
            j++;
            if(i == word1[w1i].size()){
                i=0;
                w1i++;
            }
            if(j == word2[w2i].size()){
                j=0;
                w2i++;
            }
        }
        if(w1i == word1.size() && w2i == word2.size())
            return true;
        return false;
    }
};