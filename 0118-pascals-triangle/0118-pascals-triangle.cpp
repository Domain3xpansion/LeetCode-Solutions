class Solution {
public:
    vector<vector<int>> generate(int numRows){
        vector<vector<int>> pascalTriangle;
        int n = numRows;
        for (int i=1; i<=n; i++){
            vector<int> row; 
            int coef = 1;

            for (int j = 1; j <= i; j++){
                row.push_back(coef); 
                coef = coef * (i - j) / j;
            }
            pascalTriangle.push_back(row);
        }
        return pascalTriangle;
    }
};