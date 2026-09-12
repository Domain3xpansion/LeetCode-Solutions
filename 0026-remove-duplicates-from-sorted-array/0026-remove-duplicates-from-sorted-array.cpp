class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // Brute force
        set<int> uniqueElements;
        for(int val:nums){
            uniqueElements.insert(val);
        }
        int i = 0;
        for(int val : uniqueElements){
            nums[i] = val;
            i++;
        }
        return i;
        /*int i = 0;
        for(int j=1; j<nums.size(); j++){
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i+1; //Since i points to the position after the last unique element, the number of unique 
        // elements is equal to i + 1*/
    }
};