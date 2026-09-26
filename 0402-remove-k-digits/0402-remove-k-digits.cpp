class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == num.size())
            return "0";
        stack<char> st;
        string res = "";
        for(int i=0; i<num.size(); i++){
            while(!st.empty() && num[i]<st.top() && k>0){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        while(k>0){
            /* k may still be > 0 after the loop
            num = "12345" and k = 2
            the above while condition never triggers because the number is already increasing.*/
            st.pop();
            k--; 
        }
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        int start = 0;
        while(start < res.size() && res[start] == '0'){
            start++;
        }
        res = res.substr(start);
        return res.empty() ? "0" : res;
    }
};