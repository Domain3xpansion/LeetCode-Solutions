class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> onetoone;
        for(int i = 0; i < s.size(); i++){
            char c1 = s[i];
            char c2 = t[i]; 
            if(!onetoone.count(c1)){  // checking if c1 already exists or not
            // will enter in the if block only if c1 doesn't exist in the map
                for(auto& [key, val]:onetoone){
                    if(val == c2)
                        return false;
                        /*checking if c2, which will be the value in our map, is it already mapped to any key present in the map, if yes, then return false
                        if not, then insert both c1 and c2 where c2 will be c1's value*/
                }
                onetoone.insert({c1, c2});
            }
            else{
                /*will come to the else part only if a key already exists
                that means that existing key will have a value mapped to it*/
                if(onetoone[c1] != c2)
                /* if that value which is mapped to the existing is not equal to the current value, then return false
                example: in foo -> bar,
                    the 2nd o will bring the control to this else block here
                    f -> b, o -> a till now
                    a != r so return false because "No two characters may map to the same character" */ 
                    return false;
            }
        }
        return true;
    }
};