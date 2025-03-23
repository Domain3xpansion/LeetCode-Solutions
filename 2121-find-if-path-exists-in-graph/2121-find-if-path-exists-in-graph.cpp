class Solution {
public:
    void dfs(int s, vector<vector<int>>& adjl, vector<int>& vis, vector<int>& ls){
        vis[s] = 1;
        ls.push_back(s);
        for(auto it: adjl[s]){
            if(!vis[it]){
                dfs(it, adjl, vis, ls);
            }
        }
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjl(n); // for storing the adjacency list
        for(int i=0; i<edges.size(); i++){  // edges.size() denotes the no of edges present in the graph
            int u = edges[i][0];
            int v = edges[i][1];
            adjl[u].push_back(v);
            adjl[v].push_back(u);
        }
        vector<int> vis(n, 0), ls;
        dfs(source, adjl, vis, ls);
        return find(ls.begin(), ls.end(), destination) != ls.end();
        
    }
};