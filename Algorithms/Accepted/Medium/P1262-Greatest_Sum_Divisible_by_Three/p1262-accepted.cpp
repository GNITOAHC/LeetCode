#define pb push_back
#define testArray; \
for (int i=0; i<5; ++i){ \
    for (int j=0; j<nums.size(); ++j){ \
        printf("%11d ", array[i][j]); \
    } cout << endl; \
}
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> array;
        array.pb(nums);
        
        // push_back mod3
        vector<int> mod3;
        for (int i=0; i<nums.size(); ++i){
            mod3.pb(nums[i]%3);
        }
        array.pb(mod3);
        // push mod3 end
        
        vector<int> r0(nums.size(), INT_MIN);
        vector<int> r1(r0), r2(r0);
        
        array.pb(r0);
        array.pb(r1);
        array.pb(r2);
        
        if (array[1][0] == 0)
            array[2][0] = array[0][0];
        else if (array[1][0] == 1)
            array[3][0] = array[0][0];
        else array[4][0] = array[0][0];
        
        // testArray;
        // cout << endl;
        for (int i=1; i<nums.size(); ++i){
            // cout << "nums.size() = " << nums.size() << endl;
            if (array[1][i] == 0){
                array[2][i] = max(array[0][i], array[2][i-1]+array[0][i]);
                if (array[3][i-1] > 0){
                    array[3][i] = array[3][i-1]+array[0][i];
                } else
                    array[3][i] = array[3][i-1];
                if (array[4][i-1] > 0){
                    array[4][i] = array[4][i-1]+array[0][i];
                } else 
                    array[4][i] = array[4][i-1];
            }
            else if (array[1][i] == 1){
                array[2][i] = max(array[2][i-1], array[4][i-1] + array[0][i]);
                array[3][i] = max(array[3][i-1], array[2][i-1] + array[0][i]);
                array[4][i] = max(array[4][i-1], array[3][i-1] + array[0][i]);
                array[3][i] = max(array[3][i], array[0][i]);
            }
            // else if (array[1][i] == 2){
            else {
                array[2][i] = max(array[2][i-1], array[3][i-1] + array[0][i]);
                array[3][i] = max(array[3][i-1], array[4][i-1] + array[0][i]);
                array[4][i] = max(array[4][i-1], array[2][i-1] + array[0][i]);
                array[4][i] = max(array[4][i], array[0][i]);
            }
        }
        
        testArray;
        cout << endl;
        if (array[2][nums.size()-1] < 0) return 0;
        return array[2][nums.size()-1];
    }
};