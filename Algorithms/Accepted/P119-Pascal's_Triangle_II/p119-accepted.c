

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    rowIndex += 1;
    * returnSize = rowIndex;
    int ** a = (int **) malloc (sizeof(int *) * rowIndex);
    for (int i=0; i<rowIndex; ++i){
        a[i] = (int *) malloc (sizeof(int) * (i+1));
        memset (a[i], 1, i+1);
    }
    
    a[0][0] = 1;
    for (int i=1; i<rowIndex; ++i){
        a[i][0] = 1;
        a[i][i] = 1;
        for (int j=1; j<i; ++j){
            a[i][j] = a[i-1][j-1] + a[i-1][j];
        }
    }
    
    return a[rowIndex-1];

}