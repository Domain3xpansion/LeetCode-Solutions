class Solution {
public:
    vector<string> tokens(string a){
        stringstream ss(a);
        string token = "";
        vector<string> tokens;
        while(getline(ss, token, '.')){
            tokens.push_back(token);
        }
        return tokens;
    }
    int compareVersion(string version1, string version2){
        vector<string> vers1 = tokens(version1);
        vector<string> vers2 = tokens(version2);
        int v1 = vers1.size(), v2 = vers2.size(), i=0;
        while(i < v1 || i < v2){
            int a = i < v1 ? stoi(vers1[i]) : 0;
            int b = i < v2 ? stoi(vers2[i]) : 0;
            if(a < b)
                return -1;
            else if(a > b)
                return 1;
            else
                i++;
        }
        return 0;
    }
};