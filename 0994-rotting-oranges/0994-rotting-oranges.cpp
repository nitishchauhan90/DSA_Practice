class Solution {
public:
    // int solve(vector<vector<int>>& grid,int& n,int& m,int i,int j,vector<vector<bool>>visit){
    //     if(i>=n||i<0||j>=m||j<0||grid[i][j]==0||visit[i][j]){
    //         return 0;
    //     }
    //     visit[i][j]=true;
    //     int result = 0;
    //     result = 1+ solve(grid,n,m,i+1,j,visit) + solve(grid,n,m,i,j+1,visit) +  solve(grid,n,m,i-1,j,visit) + solve(grid,n,m,i,j-1,visit) ;
    //     return result;
    // }
    int orangesRotting(vector<vector<int>>& grid) {
        // int n = grid.size();
        // int m = grid[0].size();
        // vector<vector<bool>>visit(n,vector<bool>(m,false));
        // int result = INT_MAX;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         if(grid[i][j]==2&&!visit[i][j]){
        //             result = min(result,solve(grid,n,m,i,j,visit));
        //         }
        //     }
        // }
        // return result==INT_MAX ? -1 : result;
        int n = grid.size();

        int m = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {

                    q.push({i, j});

                } else if (grid[i][j] == 1) {

                    fresh++;

                }

            }

        }

        int minutes = 0;

        int dr[] = {-1, 1, 0, 0};

        int dc[] = {0, 0, -1, 1};

        while (!q.empty() && fresh > 0) {

            int size = q.size();

            for (int k = 0; k < size; k++) {

                auto [i, j] = q.front();

                q.pop();

                for (int d = 0; d < 4; d++) {

                    int ni = i + dr[d];

                    int nj = j + dc[d];

                    if (ni >= 0 && ni < n &&

                        nj >= 0 && nj < m &&

                        grid[ni][nj] == 1) {

                        grid[ni][nj] = 2;

                        fresh--;

                        q.push({ni, nj});

                    }

                }

            }

            minutes++;

        }

        return fresh == 0 ? minutes : -1;
    }
};