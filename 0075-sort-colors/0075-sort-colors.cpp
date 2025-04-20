class Solution {
public:
    void sortColors(vector<int>& nums) {
        int high = nums.size() - 1;
        int low = 0;
        int mid = 0;
        while (mid <= high){
            if (nums[mid] == 0){
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            }else if(nums[mid] == 1)
                mid++;
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        /*
        int c0 = 0, c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++) {
            if(p[i] == 0)
                c0++;
            else if(p[i] == 1)
                c1++;
            else
                c2++;
        }
        for(int i = 0; i < c0; i++)
            p[i] = 0;
        for(int i = c0; i < c0 + c1; i++)
            p[i] = 1;
        for(int i = c0 + c1; i < n; i++)
            p[i] = 2;
        */
    }
};