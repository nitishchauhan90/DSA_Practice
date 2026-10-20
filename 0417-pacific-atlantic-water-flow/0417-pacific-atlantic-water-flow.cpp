class Solution {
public:
    void solve(vector<vector<int>>& heights,int i, int j, vector<vector<bool>>& visited,int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m ||
            visited[i][j]) {
            return;
        }
        visited[i][j] = true;
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
            if (ni >= 0 && ni < n &&
                nj >= 0 && nj < m &&
                !visited[ni][nj] &&
                heights[ni][nj] >= heights[i][j]) {
                solve(heights, ni, nj, visited, n, m);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        for (int j = 0; j < m; j++) {
            solve(heights, 0, j, pacific, n, m);
        }

        for (int i = 0; i < n; i++) {
            solve(heights, i, 0, pacific, n, m);
        }
        for (int j = 0; j < m; j++) {
            solve(heights, n - 1, j, atlantic, n, m);
        }

        for (int i = 0; i < n; i++) {
            solve(heights, i, m - 1, atlantic, n, m);
        }

        vector<vector<int>> result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};