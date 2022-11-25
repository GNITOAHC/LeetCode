class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int *ans[triangle.size()];
        for (int i = 0; i < triangle.size(); ++i){
            ans[i] = new int[i + 1];
            for (int j = 0; j <= i; ++j)
                ans[i][j] = INT32_MAX;
        }
            
        ans[0][0] = triangle[0][0];
        for (int i = 1; i < triangle.size(); ++i){
            ans[i][0] = ans[i - 1][0] + triangle[i][0];
            ans[i][i] = ans[i - 1][i - 1] + triangle[i][i];
            for (int j = 1; j < i; ++j)
                ans[i][j] = min(ans[i - 1][j], ans[i - 1][j - 1]) + triangle[i][j];
        }
        
        int a = INT32_MAX;
        for (int i = 0; i < triangle.size(); ++i)
            a = min(a, ans[triangle.size() - 1][i]);
        return a;
    }
};