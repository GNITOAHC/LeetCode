#define pb push_back
class Solution {
public:
    bool havebefore(int a, int b, int c, vector<vector<int>>& array){
        for (int i=0; i<array.size(); ++i){
           if (array[i][0] == a && array[i][1] == b && array[i][2] == c)
               return true;
        }
        return false;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i=0; i<nums.size(); ++i) cout << nums[i] << " ";
        
        vector<vector<int>> array;
        for (int i=0; i<nums.size()-2; ++i){
            if (nums.size() < 3) break;
            int a = i+1, b = nums.size()-1;
            
            while(a < b){
                if (nums[i] > 0) break;
                if (nums[i] + nums[a] + nums[b] == 0){
                    if (havebefore(nums[i], nums[a], nums[b], array) == false){
                        vector<int> ans = {nums[i], nums[a], nums[b]};
                        array.pb(ans);
                    }
                }
                if (nums[i] + nums[a] + nums[b] > 0){
                    b -= 1;
                }
                // else if (nums[i] + nums[a] + nums[b] <= 0){
                else a += 1;
                //     a += 1;
                // }
            }
        }
        return array;
    }
};
