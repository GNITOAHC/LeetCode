

bool isValid(char * s){
    int buffer = 0;
    while (*(s+buffer) != '\0') buffer++;
    int stack[buffer+1], current = -1;
    for (int i=0; i<buffer; i++){
        if (*(s+i) == '(') stack[++current] = 1;
        else if (*(s+i) == '[') stack[++current] = 2;
        else if (*(s+i) == '{') stack[++current] = 3;
        
        else if (*(s+i) == ')'){
            if (current == -1) return false;
            if (stack[current] == 1) current--;
            else break;
        }
        
        else if (*(s+i) == ']'){
            if (current == -1) return false;
            if (stack[current] == 2) current--;
            else break;
        }
        
        else if (*(s+i) == '}'){
            if (current == -1) return false;
            if (stack[current] == 3) current--;
            else break;
        }
    }
    
    if (current == -1) return true;
    else return false;
    
}
