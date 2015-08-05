int removeDuplicates(int* nums, int numsSize) {
    int i, j=1, invalidVal=nums[0]-1;
    for(i=1; i<numsSize; i++) {
        if (nums[i] != nums[i-j]) {
            j=1;
        } else {
            nums[i] = invalidVal;
            j++;
        }
    }
    for (i=0,j=0; i<numsSize; i++) {
        if (nums[i] != invalidVal) {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
}
