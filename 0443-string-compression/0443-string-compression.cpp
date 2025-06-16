class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int n_len = 0;
        for(int i=0; i<n;){
            char ch = chars[i];
            int count = 0;
            while(i < n && ch == chars[i]){
                count++;
                i++;
            }
            chars[n_len] = ch;
            n_len++;
            if(count>1){
                string strcount = to_string(count);
                for(char &c : strcount){
                    chars[n_len] = c;
                    n_len++;
                }
            }
        }
        return n_len;
    }
};