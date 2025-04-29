class Solution {
public:
    int binarysearch(vector<int> &arr, int target, int s, int e){
        if(s>e)
            return -1;
        int mid = s+(e-s)/2;
        if(arr[mid]==target)
            return mid;
        if(target>arr[mid])
            return binarysearch(arr, target, mid+1, e);
        return binarysearch(arr, target, s, mid-1);
    }

    int search(vector<int>& nums, int target) {
        /*int s = 0, e = nums.size()-1;
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(target == nums[mid])
                return mid;
            else if(target > nums[mid])
                s = mid + 1;
            else
                e = mid - 1;
        }
        return -1;
        */
        return binarysearch(nums, target, 0, nums.size()-1);
    }
};