int missingNumber(int* nums, int numsSize){
    int temp, i;
    while(i<numsSize)
    {
        int correct = nums[i];
        if(nums[i] < numsSize && nums[i]!=nums[correct])
        {
            temp = nums[i];
            nums[i] = nums[correct];
            nums[correct] = temp;
        }
        else
        {
            i++;
        }
    }
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]!=i)
            return i;
    }
    return numsSize;
}