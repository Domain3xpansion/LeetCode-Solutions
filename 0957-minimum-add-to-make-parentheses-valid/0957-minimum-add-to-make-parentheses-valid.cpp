class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, unmatched_closing_parentheses = 0;
        /* open = unmatched (
        If the string is like this => "()()", 
        open variable's transition will be like => +1 -> 0 -> +1 -> 0 and unmatched_closing_parentheses will stay 0. So, 0 + 0 = 0

        and unmatched_closing_parentheses = unmatched )
        If the string is like this => "))(), 
        unmatched_closing_parentheses variable's transition will be like => +1 -> +2 and open variable's transition will be like +1 -> 0. So, result = 2 + 0 = 2" 

        Good example = "()))((" */
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