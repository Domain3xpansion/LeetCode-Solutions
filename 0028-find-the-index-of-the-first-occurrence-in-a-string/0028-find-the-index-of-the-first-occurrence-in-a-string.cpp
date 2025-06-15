class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        int j;
        for(int i=0; i<n; i++){
            j = 0;
            while(j<m){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
                if(haystack[i+j]==needle[j]){
                    j++;
                }
                if(j==m)
                    return i;
            }
        }
        return -1;
    }
};