class Solution {
private:
    void dfs(int i, vector<vector<int>>& adjl, vector<int>& vis){
        vis[i] = 1;
        for(auto it: adjl[i]){
            if(!vis[it]){
                dfs(it, adjl, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<vector<int>> adjl(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                count++;
                dfs(i, adjl, vis);
            }
        }
        return count;
    }
};