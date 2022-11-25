


char * longestCommonPrefix(char ** strs, int strsSize){
    int currentlength = strlen(strs[0]);
    
    for (int i=1; i<strsSize; i++){
        // const int len = strlen(strs[i]);
        // currentlength = currentlength > len ? len : currentlength;
        if (strlen(*(strs+i)) < currentlength) currentlength = strlen(*(strs+i));
    }
    
    char * ans = (char *) malloc (sizeof(char) * 200);
    memset(ans, 0, 200);
    
    if (currentlength == 0){
        char * ans0 = """";
        return ans0;
    } else {
           
        for (int i=0; i<currentlength; ++i){
            for (int j=1; j<strsSize; ++j){
                if (*(*(strs+j)+i) != *(*strs+i)) return ans;
                // if (strs[j][i] != strs[0][i]) return ans;
            }
            *(ans+i) = *(*strs+i);
        }
        
    }
    
    return ans;
}
