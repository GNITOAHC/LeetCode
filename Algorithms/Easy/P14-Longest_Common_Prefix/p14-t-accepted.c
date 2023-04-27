

char * longestCommonPrefix(char ** strs, int strsSize){
    int currentlength = strlen(strs[0]);
    for (int i = 1; i < strsSize; ++i){
        const int len = strlen(strs[i]);
        currentlength = currentlength > len ? len : currentlength;
    }
    
    char *ans = malloc(sizeof(char) * 200);
    memset(ans, 0, 200);
    for (int i = 0; i < currentlength; ++i){
        for (int j = 1; j < strsSize; ++j)
            if (strs[j][i] != strs[0][i])
                return ans;
        ans[i] = strs[0][i];
    }
    return ans;
    
//     if (anslength == 0){
//         char * ans0 = """";
//         return ans0;
//     } else {
//         char * ans1 = (char *) malloc (sizeof(char)*anslength);
//         char temp[anslength];
//         printf("%c\n", *(*(strs)+1));
        
//         for (int i=0; i<anslength; i++){
//             printf("test\n");
//             ans1[i] = *(*(strs)+i);
//         }
        
//         printf("%c\n", ans1[0]);
        
//         return ans1;
//         printf("last test\n");
//     }
    
}
