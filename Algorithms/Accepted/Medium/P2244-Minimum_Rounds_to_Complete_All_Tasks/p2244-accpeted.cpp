class Solution {
public:
    int count(const int k){
        if (k == 1 || k == 0)
            return -1;
        if (k == 2)
            return 1;
        if (k == 3)
            return 1;
        else {
            int div = k/3, remainder = k%3;
            if (remainder == 0)
                return div;
            return div+1;
        }
    }
    
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(), tasks.end());
       
        if (tasks.size() < 2)
            return -1;
               
        int ans = 0, a = 0;
        
        while (a < tasks.size()){
            int tmp = tasks[a];
            int r = 0;
            while (a < tasks.size() && tasks[a] == tmp){
                ++r;
                ++a;
            }
            tmp = count (r);
            if (tmp == -1)
                return -1;
            else
                ans += tmp;
        }
        
        return ans;
    }
};