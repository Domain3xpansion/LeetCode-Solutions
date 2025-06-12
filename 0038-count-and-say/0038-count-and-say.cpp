class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        string s = countAndSay(n-1);
        int num = s.size(), i=0;
        string rle = "";
        while(i<num){
            char ch = s[i];
            int count = 1;
            while(i<num-1 && s[i] == s[i+1]){
                count++;
                i++;
            }
            rle += to_string(count) + string(1, ch);
            i++;
        }
        return rle;
    }
};