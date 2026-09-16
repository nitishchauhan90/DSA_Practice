class Solution {
public:
    void solve(vector<vector<char>>& board,bool& result,string s,string word,int r,int c,int idx){
        if (result) {
            return;
        }
        if (idx == word.length()) {
            result = true;
            return;
        }
        if (r < 0 || r >= board.size() ||
            c < 0 || c >= board[0].size()) {
            return;
        }
        if (board[r][c] != word[idx]) {
            return;
        }
        char temp = board[r][c];
        board[r][c] = '#';
        s += temp;
        solve(board, result, s, word,r - 1, c, idx + 1);
        solve(board, result, s, word,r + 1, c, idx + 1);
        solve(board, result, s, word,r, c - 1, idx + 1);
        solve(board, result, s, word,r, c + 1, idx + 1);
        s.pop_back();
        board[r][c] = temp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool result = false;
        string s = "";
         for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                solve(board, result, s, word,r, c, 0);
                if (result) {
                    return true;
                }
            }
        }
        return false;
    }
};