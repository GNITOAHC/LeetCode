class Solution {
private: 
    void boardview (vector<vector<char>>& board) {
        int lenx = board[0].size(), leny = board.size();
        for (int i=0; i<leny; ++i) {
            for (int j=0; j<lenx; ++j)
                cout << board[i][j] << " ";
            cout << endl;
        }
    }
public:
    bool trace (vector<vector<char>> board, const string word, const int index, const int x, const int y) {
        // boardview (board);
        // printf("(y, x) = (%d, %d)\n", y, x);
        if (index >= word.length() || x < 0 || y < 0 || x >= board[0].size() || y >= board.size())
            return false;
        if (board[y][x] != word[index])
            return false;
        
        if (board[y][x] == word[index]) {
            // boardview (board);
            if (index == word.length()-1)
                return true;
            else {
                board[y][x] = '.';
                bool r1 = trace (board, word, index+1, x+1, y) || trace (board, word, index+1, x, y+1);
                bool r2 = trace (board, word, index+1, x-1, y) || trace (board, word, index+1, x, y-1);
                return (r1 || r2);
            }
        }
        return false;
    };
    
    bool exist(vector<vector<char>>& board, string word) {
        // cout << word.length() << " " << word[5] << endl;
        // cout << board.size() << " " << board[0].size() << endl;
        for (int i=0; i<board.size(); ++i) {
            for (int j=0; j<board[0].size(); ++j) {
                if (trace (board, word, 0, j, i))
                    return true;
            }
        }
        
        return false;
    }
};