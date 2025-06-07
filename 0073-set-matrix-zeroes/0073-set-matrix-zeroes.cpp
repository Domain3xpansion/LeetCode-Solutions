class Solution {
public:
    /*Brute force
    Time Complexity = O(m*n*(m+n)) + O(m*n) = = O(m*n*(m+n))          Space Complexity = O(1)
    
    1) for the 1st nested for loops: O(m*n) to scan every element
    
    2) for each zero found: O(m+n) to mark entire row and column
       In worst case (all elements are 0), every element triggers O(m + n) operations
       So it's O(m Ã n) iterations, each doing O(m+n) work
  
    3) for the 2nd nested for loops: O(m*n) where we are replacing every 'a' with 0

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
    Total Time Complexity = O(2*m*n) = O(m*n)
    Space complexity = O(m) + O(n) = O(m+n)    (for the 2 vectors that we are using for hashing)

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
        // Above nested for loop is of O(m*n)
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){  // if either of rows[i] or columns[j] has 1 in it, make the cell of "matrix" at [i][j] change to 0
                if(rows[i] || columns[j])
                    matrix[i][j] = 0;
            }
        }
        // Above nested for loop is of O(m*n)
    }*/

    /* Optimal solution
    Total T.C = O(m*n) + O(m*n) + O(m+n) = O(2*m*n) + O(m+n) = O(m*n)    
    (Constants don't matter: O(2*m*n) = O(m*n)  AND  Lower-order terms become negligible: As m,n grow large, m*n dominates m+n)

    Space Complexity = O(1)*/

    void setZeroes(vector<vector<int>>& matrix) {  
        int col0 = 1;
        int m = matrix.size();     
        int n = matrix[0].size();
        // Pass 1: Mark zeros (O(m*n))
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
        // Pass 2: Set zeros based on markers (O(m*n))
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(matrix[i][j] != 0){
                    if(matrix[0][j] == 0 || matrix[i][0] == 0)
                        matrix[i][j] = 0;
                }
            }
        }
        // Handle first row followed by first column because the first row depends on the first column (O(m+n))
        if(matrix[0][0] == 0){     // First row: O(n)
            for(int j=0; j<n; j++){
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0){        // First column: O(m)
            for(int i=0; i<m; i++){
                matrix[i][0] = 0;
            }
        }
    }
};