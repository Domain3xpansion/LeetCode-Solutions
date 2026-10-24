class Solution {
public:
    int numberOfSubstrings(string s) {
        /*int n = s.size(), count = 0;
        for(int i=0;i<n;i++){
            bool a = false, b = false, c = false;
            for(int j=i; j<n; j++){
                if(s[j] == 'a') a = true;
                if(s[j] == 'b') b = true;
                if(s[j] == 'c') c = true;
                if(a && b && c){
                    count = count + (n-j);
                    break;
                }
            }
        }
        return count;*/

        int n = s.size(), count = 0;
        int lastseen_a = -1, lastseen_b = -1, lastseen_c = -1;
        for(int i=0;i<n;i++){
            if(s[i] == 'a') lastseen_a = i;
            if(s[i] == 'b') lastseen_b = i;
            if(s[i] == 'c') lastseen_c = i;
            if(lastseen_a != -1 && lastseen_b != -1 && lastseen_c != -1)
                count += min({lastseen_a, lastseen_b, lastseen_c}) + 1;
        }
        return count;
    }
};