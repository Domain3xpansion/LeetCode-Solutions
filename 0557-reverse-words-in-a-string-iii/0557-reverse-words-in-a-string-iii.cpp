class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        for(int i=0; i<n; i++){
            if(s[i] != ' '){
                int j = i;
                while(j<n && s[j] != ' '){
                    j++;
                }
                int left = i, right = j-1;
                while(left<right){
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
                i = j;
            }
        }
        return s;
    }
};