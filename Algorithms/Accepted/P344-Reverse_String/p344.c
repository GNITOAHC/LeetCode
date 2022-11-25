

void reverseString(char* s, int sSize){
    char re[sSize+1];
    if (sSize == 1)
        return;
    else if (sSize%2 == 0){
        char tmp;
        for (int i=0, j=sSize-1; i<=(sSize/2)-1; ++i, --j){
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }
    else if (sSize%2 == 1){
        char tmp;
        for (int i=0, j=sSize-1; i<=(sSize/2); ++i, --j){
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }

    return;
}