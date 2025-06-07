class Solution {
public:
    /*Brute force
    Time Complexity = O(m * n) * O(m + n) + O(m * n)      Space Complexity = O(1)
    
    for the 1st nested for loops: O(m Ã n) to scan every element
    for each zero found: O(m + n) to mark entire row and column
    for the 2nd nested for loops: O(m Ã n) where we are replacing every 'a' with 0

    void markrows(vector<vector<int>>& matrix, int i){
        int n = matrix[0].size();
        for(int j = 0; j < n; j++){
            if(matrix[i][j] != 0)
                matrix[i][j] = 'a';
        }
    }

    void markcolumns(vector<vector<int>>& matrix, int j){
        int m = matrix.size();
        for(int i = 0; i < m; i++){
            if(matrix[i][j] != 0)
                matrix[i][j] = 'a';
        }
    }
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();     //stores no of rows
        int n = matrix[0].size();     //stores no of columns
        for(int i = 0; i < m; i++){    
            for (int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    markrows(matrix, i);   // O(m)
                    markcolumns(matrix, j);   // O(n)
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 'a')
                    matrix[i][j] = 0;
            }
        }
    }*/

    /* Better solution
    void setZeroes(vector<vector<int>>& matrix) {  
        int m = matrix.size();     //stores no of rows
        int n = matrix[0].size();     //stores no of columns
        vector<int> rows(m, 0);    //responsible for marking cells with 1 for which columns have a min of one 0
        vector<int> columns(n, 0);   //responsible for marking cells with 1 for which rows have a min of one 0
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    rows[i] = 1;
                    columns[j] = 1;
                }
            }
        }
        //This above  O(m*n)
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){  // if either of rows[i] or columns[j] has 1 in it, make the cell of "matrix" at [i][j] change to 0
                if(rows[i] || columns[j])
                    matrix[i][j] = 0;
            }
        }
        //This above nested for loop is of O(m*n)
        //Total time complexity = O(2*m*n) 
        //Space complexity = O(m) + O(n) (for the 2 vectors that we are using for hashing)
    }*/

    // Optimal solution
    void setZeroes(vector<vector<int>>& matrix) {  
        int col0 = 1;
        int m = matrix.size();     
        int n = matrix[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    if(j != 0)
                        matrix[0][j] = 0;
                    else
                        col0 = 0;
                }
            }
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] != 0){
                    if(matrix[0][j] == 0 || matrix[i][0] == 0)
                        matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};