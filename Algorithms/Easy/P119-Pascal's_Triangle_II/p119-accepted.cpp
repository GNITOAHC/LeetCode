#define pb push_back
#define DB cout << "DEBUG" << endl;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        ++rowIndex;
        int * a[rowIndex];
        for (int i=0; i<rowIndex; ++i)
            a[i] = new int[i+1];
        
        a[0][0] = 1;
        for (int i=1; i<rowIndex; ++i){
            a[i][0] = 1;
            a[i][i] = 1;
            for (int j=1; j<i; ++j){
                a[i][j] = a[i-1][j-1] + a[i-1][j];
            }
        }
        
        vector<int> r;
        for (int i=0; i<rowIndex; ++i){
            r.pb(a[rowIndex-1][i]);
        }
        return r;
    }
};