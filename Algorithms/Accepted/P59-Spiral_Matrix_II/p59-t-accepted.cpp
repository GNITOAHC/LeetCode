class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat;
        mat.reserve(n);
        for (int i = 0; i < n; ++i){
            vector<int> v(n);
            mat.push_back(v);
        }
        int num = 1;
        for (int i = 0; i < n >> 1; ++i){
            for (int j = i; j < n - i - 1; ++j){
                mat[i][j] = num;
                ++num;
            }
            for (int j = i; j < n - i - 1; ++j){
                mat[j][n - 1 - i] = num;
                ++num;
            }
            for (int j = i; j < n - i - 1; ++j){
                mat[n - 1 - i][n - 1 - j] = num;
                ++num;
            }
            for (int j = i; j < n - i - 1; ++j){
                mat[n - 1 - j][i] = num;
                ++num;
            }
        }
        if (n % 2)
            mat[n >> 1][n >> 1] = num;
        return mat;
    }
};