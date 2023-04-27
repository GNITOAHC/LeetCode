

// Boyer-Moore Voting
int majorityElement(int* nums, int numsSize){
    int vote = nums[0], count = 1;
    for (int i=1; i<numsSize; ++i){
        if (nums[i] == vote){
            count += 1;
        }
        else if (count == 1){
            vote = nums[i];
        }
        else {
            count -= 1;
        }
    }
    
    return vote;
}