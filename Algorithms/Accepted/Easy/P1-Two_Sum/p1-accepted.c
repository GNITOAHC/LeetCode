

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct Pair{
	int val;
	int index;
}Pair;

int compair(const void * a, const void * b){
	const Pair * _a = (Pair *) a;
	const Pair * _b = (Pair *) b;
	return _a->val > _b->val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int *ans = (int *)malloc(sizeof(int) * 2);
	Pair arr[numsSize];
	for (int i=0; i<numsSize; ++i){
		arr[i].val = *(nums+i);
		arr[i].index = i;
	}
    
	qsort(arr, numsSize, sizeof(Pair), compair);

	int start = 0, end = numsSize-1;
	while(start < end){
		if (arr[start].val + arr[end].val > target)
			--end;
		else if (arr[start].val + arr[end].val < target)
			++start;
		else{
			ans[0] = arr[start].index;
			ans[1] = arr[end].index;
			break;
		}
	}
	*returnSize = 2;
	return ans;
}

