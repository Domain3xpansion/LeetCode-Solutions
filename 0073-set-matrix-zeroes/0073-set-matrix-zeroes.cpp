class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();     //stores no of rows
        int n = matrix[0].size();     //stores no of columns
        vector<int> rows(m, 0);
        vector<int> columns(n, 0);
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    columns[j] = 1;
                }
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(rows[i] || columns[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
