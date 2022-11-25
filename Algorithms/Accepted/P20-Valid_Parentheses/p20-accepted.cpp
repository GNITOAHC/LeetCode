class Solution {
public:
    bool isValid(string s) {
        int length = s.length();
        int stack[length], current=0;
        cout << length << endl;
        
        if (s[0] == '(') stack[0] = 1;
        else if (s[0] == '[') stack[0] = 2;
        else if (s[0] == '{') stack[0] = 3;
        else return false;
        
        for (int i=1; i<length; i++){
            if (s[i] == '(') stack[++current] = 1;
            else if (s[i] == '[') stack[++current] = 2;
            else if (s[i] == '{') stack[++current] = 3;
            
            else if (s[i] == ')'){
                if (current == -1) return false;
                if (stack[current] == 1) current--;
                else return false;
            }
            
            else if (s[i] == ']'){
                if (current == -1) return false;
                if (stack[current] == 2) current--;
                else return false;
            }
            
            else if (s[i] == '}'){
                if (current == -1) return false;
                if (stack[current] == 3) current--;
                else return false;
            }
        }
        if (current == -1) return true;
        else return false;
    }
};
