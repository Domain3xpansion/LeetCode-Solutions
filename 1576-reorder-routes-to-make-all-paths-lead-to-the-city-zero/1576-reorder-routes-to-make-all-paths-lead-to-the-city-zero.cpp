class Solution {
public:
    int dfs(int root, vector<vector<int>> &gr, vector<bool> &visited){
        int edges = 0;
        visited[root] = 1;
        for(auto i : gr[root]){
            if(!visited[abs(i)]){
                edges += dfs(abs(i), gr, visited) + (i>0);
            }
        }
        return edges;
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto i : connections){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(-i[0]);
        }
        return dfs(0, graph, vector<bool> (n) = {});
    }
};