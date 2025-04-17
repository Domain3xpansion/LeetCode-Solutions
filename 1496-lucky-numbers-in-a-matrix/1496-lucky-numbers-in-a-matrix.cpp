class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), x=0, y=0;    
        vector<int> MinR(m, INT_MAX), MaxC(n, INT_MIN), luckynums;         
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                MinR[i] = min(MinR[i], matrix[i][j]);
            }
        }
        for(int j=0; j<n; j++){
            for(int i=0; i<m; i++){
                MaxC[j] = max(MaxC[j], matrix[i][j]);
            }
        }
        unordered_set<int> us(MinR.begin(), MinR.end());
        for(int num : MaxC){
            if(us.count(num))
                luckynums.push_back(num);
        }
        return luckynums;
    }
};