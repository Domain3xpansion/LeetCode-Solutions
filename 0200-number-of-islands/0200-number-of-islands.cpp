class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        int neighbourrow[] = {-1, 0, 1, 0};
        int neighbourcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + neighbourrow[i];
                int ncol = col + neighbourcol[i];
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m 
                && grid[nrow][ncol] == '1' && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), count = 0;
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int row = 0; row < n; row++){
            for(int col=0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    count++;
                    bfs(row, col, vis, grid);                }
            }
        }
        return count;
    }
};