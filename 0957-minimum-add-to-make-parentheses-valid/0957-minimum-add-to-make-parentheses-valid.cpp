class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, unmatched_closing_parentheses = 0;
        for(char c : s){
            if(c == '('){
                open++;
            }
            else{
                if(open > 0)
                    open--;
                else
                    unmatched_closing_parentheses++;
            }
        }
        return open + unmatched_closing_parentheses;
    }
};