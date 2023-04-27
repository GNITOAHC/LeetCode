#define pb push_back
class Solution {
public:
    string deduce (string s, const int k) {
        string a;
        for (int i=0; i<s.length(); ++i){
            int tmp = 0;
            for (int j=0; j<k; ++j){
                if(j == k-1){
                    tmp += s[i]-'0';
                    break;
                }
                tmp += (s[i++]-'0');
                if (i >= s.length()){
                    // i += j;
                    break;
                }
            }
            // cout << "tmp = " << tmp << endl;
            std::string k = std::to_string(tmp);
            for (int j=0; j<k.length(); ++j){
                a.pb(k[j]);
            }
            // cout << a << endl;
        }
        
        return a;
    }
    
    string digitSum (string s, int k) {
        string a (s);
        while (a.length() > k){
                a = deduce (a, k);
        }
        
        return a;
    }
};