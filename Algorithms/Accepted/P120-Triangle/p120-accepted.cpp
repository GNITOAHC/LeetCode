class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int * ans[triangle.size()];
        for (int i=0; i<triangle.size(); ++i){
            ans[i] = new int[i+1];
            for (int j=0; j<i; ++j){
                ans[i][j] = INT_MAX;
            }
        }
        
        ans[0][0] = triangle[0][0];
        
        for (int i=1; i<triangle.size(); ++i){
            ans[i][0] = ans[i-1][0] + triangle[i][0];
            ans[i][i] = ans[i-1][i-1] + triangle[i][i];
            for (int j=1; j<i; ++j){
                ans[i][j] = min(ans[i-1][j-1] + triangle[i][j], ans[i-1][j] + triangle[i][j]);
            }
        }

        int a = ans[triangle.size()-1][0];
        for (int i=0; i<triangle.size(); ++i){
             a = ans[triangle.size()-1][i] < a ? ans[triangle.size()-1][i] : a;
        }
        
        return a;
    }
};