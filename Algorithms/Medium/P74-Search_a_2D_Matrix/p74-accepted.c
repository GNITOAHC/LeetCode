

// Binary Search
bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int arr[10000] = {0}, counter = 0;
    
    for (int i=0; i<matrixSize; ++i){
        for (int j=0; j<*matrixColSize; ++j){
            arr[counter] = matrix[i][j];
            ++counter;
        }
    }
    
    int front = 0, end = (matrixSize * (* matrixColSize))-1;
    
    if (end == 0){
        if (arr[0] == target) return true;
        return false;
    }
    
    printf("end = %d\n", end);
    int current = (front+end)/2;
    
    while (front < end){
        if (arr[current] == target || arr[front] == target || arr[end] == target)
            return true;
        if (arr[current] > target){
            end = current-1;
            current = (front+end)/2;
        }
        else if (arr[current] < target){
            front = current+1;
            current = (front+end)/2;
        }
    }
    
    return false;
}
