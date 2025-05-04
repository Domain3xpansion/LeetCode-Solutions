class Solution {
public:
    vector<string> helper(string p, string up){
        if(up.empty()){
            vector<string> l;
            l.push_back(p);
            return l;
        }
        int digit = up[0] - '0';
        vector<string> list;
        if(digit==7){
            for(int i=(digit-2)*3; i<=(digit-1)*3; i++){
                char ch = (char)('a' + i);
                vector<string> subList = helper(p + ch, up.substr(1));
                list.insert(list.end(), subList.begin(), subList.end());
            }
        }else if(digit == 9){
            for(int i=(digit-2)*3+1; i<=(digit-1)*3+1; i++){
                char ch = (char)('a' + i);
                vector<string> subList = helper(p + ch, up.substr(1));
                list.insert(list.end(), subList.begin(), subList.end());
            }
        }else if(digit == 8){
            for(int i=(digit-2)*3+1; i<(digit-1)*3+1; i++){
                char ch = (char)('a' + i);
                vector<string> subList = helper(p + ch, up.substr(1));
                list.insert(list.end(), subList.begin(), subList.end());
            }
        }else{
            for(int i=(digit-2)*3; i<(digit-1)*3; i++){
                char ch = (char)('a' + i);
                vector<string> subList = helper(p + ch, up.substr(1));
                list.insert(list.end(), subList.begin(), subList.end());
            }
        }
        return list;
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string p;
        return helper(p, digits);
    }
};