class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();     //stores no of rows
        int n = matrix[0].size();     //stores no of columns
        for (int i = 0; i < m; i++) {    
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    markrows(matrix, i);   // O(m)
                    markcolumns(matrix, j);   // O(n)
                }
            }
        }
        //this whole function is of O((m*n)*(m+n))

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 'a') {
                    matrix[i][j] = 0;
                }
            }
        }
        //this whole function is of O(m*n)
    }

private:
    void markrows(vector<vector<int>>& matrix, int i) {
        int n = matrix[0].size();
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = 'a';
            }
        }
    }

    void markcolumns(vector<vector<int>>& matrix, int j) {
        int m = matrix.size();
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] != 0) {
                matrix[i][j] = 'a';
            }
        }
    }
    //Brute force solution
    //Total time complexity is near about n^3 which is not at all desirable
};
