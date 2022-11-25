

bool isValid(char * s, int front, int back){
    for (; front<back; ++front, --back){
        if (s[front] != s[back])
            return false;
    }
    return true;
}
bool validPalindrome(char * s){
    int len = strlen(s);
        
    for (int i=0, j=len-1; i<=j; ++i, --j){
        if (s[i] != s[j]){
            return (isValid(s, i+1, j) || isValid(s, i, j-1));
        }
    }
    return true;
}