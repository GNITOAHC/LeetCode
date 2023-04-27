class Solution {
public:
    int getRoman(char s){
        switch(s){
            case 'I': return 1; break;
            case 'V': return 5; break;
            case 'X': return 10; break;
            case 'L': return 50; break;
            case 'C': return 100; break;
            case 'D': return 500; break;
            case 'M': return 1000; break;
        }
        return 0;
    }
    int romanToInt(string s) { 
        int answer = 0;
        for(int i=0; i<s.length(); i++){
            if(getRoman(s[i]) >= getRoman(s[i+1])){
                
                answer += getRoman(s[i]);
            }else{
                answer -= getRoman(s[i]);
            }
        }
        return answer;
    }
};
