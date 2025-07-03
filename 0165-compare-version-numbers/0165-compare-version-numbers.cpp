class Solution {
public:
    /*vector<string> tokens(string a){
        stringstream ss(a);
        string token = "";
        vector<string> tokens;
        while(getline(ss, token, '.')){
            tokens.push_back(token);
        }
        return tokens;
    }*/
    int compareVersion(string version1, string version2){
        /*vector<string> vers1 = tokens(version1);
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
        return 0;*/

        int i = 0, j = 0;
        while(i < version1.length() || j < version2.length()){
            int num1 = 0, num2 = 0;
            while(i < version1.length() && version1[i] != '.'){
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            i++; 
            while (j < version2.length() && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }
            j++;
            if(num1 < num2) 
                return -1;
            if(num1 > num2) 
                return 1;
        }
        return 0;
    }
};