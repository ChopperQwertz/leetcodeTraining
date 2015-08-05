int removeElement(int* nums, int numsSize, int val) {
    int i, j, invalidVal=-5566;    
    for(i=0; i<numsSize; i++) 
        if (nums[i] == val) 
            nums[i] = invalidVal; 
    for (i=0,j=0; i<numsSize; i++) {
        if (nums[i] != invalidVal) {
            nums[j] = nums[i];
            j++;
        }
    }
    return j;
} 