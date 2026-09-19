class Solution {
public:
    void solveRow(int n,vector<vector<int>>& grid,int rowshift,int row){
         vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[(i - rowshift + n) % n] = grid[row][i];
        }
        for (int i = 0; i < n; i++) {
            grid[row][i] = temp[i];
        }
        
    }
    void solveCol(int n,vector<vector<int>>& grid,int colshift,int col){
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[(i - colshift+n) % n] = grid[i][col];
        }
        for (int i = 0; i < n; i++) {
            grid[i][col] = temp[i];
        }

    }
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
       for(int i=0;i<rowShift.size();i++){
            if(rowShift[i]==0){
                continue;
            }
            else{
                solveRow(n,grid,rowShift[i], i);
            }
       } 
       for(int i=0;i<colShift.size();i++){
            if(colShift[i]==0){
                continue;
            }
            else{
                solveCol(n,grid,colShift[i],i);
            }
       } 
        return grid;
    }
};