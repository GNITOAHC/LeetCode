

int romanToInt(char * s){
    int ans = 0;
    for (int i=0; i<15; i++){
        if (*(s+i+1) == '\0'){
            if (*(s+i) == 'I') ans += 1;
            else if (*(s+i) == 'V') ans += 5;
            else if (*(s+i) == 'X') ans += 10;
            else if (*(s+i) == 'L') ans += 50;
            else if (*(s+i) == 'C') ans += 100;
            else if (*(s+i) == 'D') ans += 500;
            else if (*(s+i) == 'M') ans += 1000;
            break;
        }
        else{
            if (*(s+i) == 'I') {
                if (*(s+i+1) == 'V' || *(s+i+1) == 'X'){
                    if (*(s+i+1) == 'V') ans += 4;
                    else ans += 9;
                    i+=1;
                    if (*(s+i+1) == '\0') break;
                }
                else ans += 1;
            }
            
            else if (*(s+i) == 'X') {
                if (*(s+i+1) == 'L' || *(s+i+1) == 'C'){
                    if (*(s+i+1) == 'L') ans += 40;
                    else ans += 90;
                    i+=1;
                    if (*(s+i+1) == '\0') break;
                }
                else ans += 10;
            }
            
            else if (*(s+i) == 'C') {
                if (*(s+i+1) == 'D' || *(s+i+1) == 'M'){
                    if (*(s+i+1) == 'D') ans += 400;
                    else ans += 900;
                    i+=1;
                    if (*(s+i+1) == '\0') break;
                }
                else ans += 100;
            }
            
            else if (*(s+i) == 'V') ans += 5;
            else if (*(s+i) == 'L') ans += 50;
            else if (*(s+i) == 'D') ans += 500;
            else if (*(s+i) == 'M') ans += 1000;
        }
    }
    return ans;
}