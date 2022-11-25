#define pb push_back
#define DEBUG cout << "DEBUG" << endl

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> st;
        for (int i=0; i< ops.size(); ++i){
            if (ops[i][0] == 'C'){
                st.pop_back();
            }
            else if (ops[i][0] == 'D'){
                st.pb(st.back() * 2);
            }
            else if (ops[i][0] == '+'){
                st.pb(st.back() + st.at(st.size()-2));
            }
            
            else {
                st.pb(stoi(ops[i]));
                // cout << st.back() << endl;
            }
        }
        
        int ans = 0;
        for (int i=0; i<st.size(); ++i){
            ans += st[i];
        }
        
        return ans;
    }
};