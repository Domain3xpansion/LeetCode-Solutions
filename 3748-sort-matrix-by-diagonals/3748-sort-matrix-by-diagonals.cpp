class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int i=0; i<n; i++){
            sortDiagonal(grid, i, 0, false); 
        }
        for(int j=1; j<n; j++){
            sortDiagonal(grid, 0, j, true);
        }
        return grid;
    }


    void sortDiagonal(vector<vector<int>>& grid, int m, int n, bool ascending){
        int row = grid.size(), col = grid.size();
        vector<int> list;
        for (int i=m, j=n; i<row && j<col; i++, j++){
            list.push_back(grid[i][j]);
        }
        if(ascending)
            sort(list.begin(), list.end());
        else
            sort(list.rbegin(), list.rend());
        int k_index = 0;
        for (int i=m, j=n; i<row && j<col; i++, j++){
            grid[i][j] = list[k_index++];
        }
    }
};