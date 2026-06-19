class Solution {
public:
    void dfs(vector<vector<int>>& image,
             int sr,
             int sc,
             int color,
             int originalColor,
             vector<vector<bool>>& visited) {

        int m = image.size();
        int n = image[0].size();

        if (sr < 0 || sc < 0 || sr >= m || sc >= n)
            return;

        if (visited[sr][sc])
            return;

        if (image[sr][sc] != originalColor)
            return;

        visited[sr][sc] = true;

        image[sr][sc] = color;

        dfs(image, sr + 1, sc, color, originalColor, visited);
        dfs(image, sr - 1, sc, color, originalColor, visited);
        dfs(image, sr, sc + 1, color, originalColor, visited);
        dfs(image, sr, sc - 1, color, originalColor, visited);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr,
                                  int sc,
                                  int color) {

        int m = image.size();
        int n = image[0].size();

        vector<vector<int>> ans = image;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int originalColor = ans[sr][sc];

        dfs(ans, sr, sc, color, originalColor, visited);

        return ans;
    }
};