class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,
             vector<bool>& visited,
             int node) {

        visited[node] = true;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[node][j] && !visited[j]) {
                dfs(isConnected, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);

        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                provinces++;
            }
        }

        return provinces;
    }
};