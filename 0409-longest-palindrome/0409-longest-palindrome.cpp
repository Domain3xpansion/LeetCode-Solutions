class Solution {
public:
    int longestPalindrome(string s) {
        int ans = 0;
        bool oddfreq = false;
        unordered_map<char, int> um;
        for(char ch: s){
            um[ch]++;
        }
        for(auto &x:um){
            if(x.second % 2 == 0){
                ans += x.second;
            }else{
                ans += x.second - 1;
                oddfreq = true;
            }
        }
        /*
        even if we have several odd-frequency characters:
            a â 3, b â 5, c â 1
        we can use the pairs from all of them:
            a â 2, b â 4, c â 0
        But we can only use one leftover character as the center.*/
        if(oddfreq)
            ans += 1;
        return ans;
    }
};