

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//     vector<int> num2(nums);
//     sort(nums.begin(), nums.end());
    
//     int i=0, j = nums.size() - 1;
//     while (true){
//         if (nums[i] + nums[j] < target){
//             i++;
//         }
//         if (nums[i] + nums[j] > target){
//             j--;
//         }
//         if (nums[i] + nums[j] == target){
//             break;
//         }
//     }
//     vector<int> ans;
//     for (int k=0; k<num2.size(); k++){
//         if (num2[k] == nums[i]) ans.push_back(k);
//         else if (num2[k] == nums[j]) ans.push_back(k);
//     }
//     return ans;
// }
// };
typedef struct pair{
    int val;
    int index;
} Pair;

int cmp(const Pair* a, const Pair* b){
    return a->val > b->val;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    Pair arr[numsSize];
    for (int i = 0; i < numsSize; ++i){
        arr[i].val = nums[i];
        arr[i].index = i;
    }
    int* ans = malloc(sizeof(int) * 2);
    qsort(arr, numsSize, sizeof(Pair), cmp);
    int i = 0, j = numsSize - 1;
    while (i < j){
        if (arr[i].val + arr[j].val > target)
            --j;
        else if (arr[i].val + arr[j].val < target)
            ++i;
        else{
            ans[0] = arr[i].index, ans[1] = arr[j].index;
            break;
        }
    }
    *returnSize = 2;
    
    return ans;
}
