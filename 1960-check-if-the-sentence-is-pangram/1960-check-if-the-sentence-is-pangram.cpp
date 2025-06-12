class Solution {
public:
    bool checkIfPangram(string sentence) {
        int count = 0;
        vector<int> vec(26, 0);
        for(char &ch : sentence){
            int x = ch - 'a';
            if(vec[x] == 0){
                vec[x]++;
                count++;
            }
        }
        if(count == 26)
            return true;
        return false;    
    }
};