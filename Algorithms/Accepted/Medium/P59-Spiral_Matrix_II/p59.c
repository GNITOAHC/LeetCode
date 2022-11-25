/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int** mat = malloc(sizeof(int*) * n);
    *returnSize = n;
    // returnColumnSizes = malloc(sizeof(int*) * n);
    int *sizes = malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i){
        mat[i] = malloc(sizeof(int) * n);
        // returnColumnSizes[i] = malloc(sizeof(int));
        sizes[i] = n;
    }
    
    int num = 1;
    for (int i = 0; i < n >> 1; ++i){
        for (int j = i; j < n - i - 1; ++j){
            mat[i][j] = num;
            ++num;
        }
        for (int j = i; j < n - i - 1; ++j){
            mat[j][n - 1 - i] = num;
            ++num;
        }
        for (int j = i; j < n - i - 1; ++j){
            mat[n - 1 - i][n - 1 - j] = num;
            ++num;
        }
        for (int j = i; j < n - i - 1; ++j){
            mat[n - 1 - j][i] = num;
            ++num;
        }
    }
    if (n % 2)
        mat[n >> 1][n >> 1] = num;
    
    for (int i = 0; i < n; ++i){
        for (int j = 0; j < n; ++j){
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
    // returnColumnSizes = &sizes;
    return mat;
}