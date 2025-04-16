class Solution{
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat){
        int m = mat.size();
        int n = mat[0].size();
        for(int i=0; i<m; i++){
            sortDiagonal(mat, i, 0);           
        }
        for(int j=1; j<n; j++){
            sortDiagonal(mat, 0, j);           
        }
        return mat;
    }

    void sortDiagonal(vector<vector<int>>& grid, int m, int n){
        int row = grid.size(); 
        int col = grid[0].size();        
        vector<int> list;
        for(int i=m, j=n; i<row && j<col; i++, j++){            
            list.push_back(grid[i][j]);
        }                           
        sort(list.begin(), list.end());
        int k_index = 0;
        for(int i=m, j=n; i<row && j<col; i++, j++){                   
            grid[i][j] = list[k_index++];
        }
    }
};