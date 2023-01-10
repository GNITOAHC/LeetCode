class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (!word.size()) return true;

        leni = board.size(), lenj = board[0].size(), lenw = word.length();
        printf("leni = %d, lenj = %d, lenw = %d\n", leni, lenj, lenw);

        for (int i = 0; i < leni; ++i) {
            for (int j = 0; j < lenj; ++j) {
                // cout << " . ";
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int i, int j, int cur) {

        if (i < 0 || i >= leni || j < 0 || j >= lenj) {
            // printf("%d, %d -> out of bound\n", i, j);
            return false;
        } else if (cur == lenw - 1) {
            // printf("%d, %d -> word end\n", i, j);
            if (word[cur] == board[i][j]) return true;
            return false;
        } else {
            // printf("%d, %d -> cur step = %c\n", i, j, board[i][j]);
            if (board[i][j] == '.') return false;
            if (board[i][j] != word[cur]) return false;
            bool found = false;
            board[i][j] = '.';
            found |= dfs(board, word, i + 1, j, cur + 1) || dfs(board, word, i - 1, j, cur + 1);
            found |= dfs(board, word, i, j + 1, cur + 1) || dfs(board, word, i, j - 1, cur + 1);
            board[i][j] = word[cur];
            return found;
        }
    }
private: 
    int leni, lenj, lenw;
};