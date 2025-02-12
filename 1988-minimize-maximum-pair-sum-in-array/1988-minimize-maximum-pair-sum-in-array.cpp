class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int i = 0, j = nums.size() - 1, minimizedmaxsum = INT_MIN;
        std::sort(nums.begin(), nums.end());     
        while(i<j){     
            if(nums[i] + nums[j] > minimizedmaxsum){
                minimizedmaxsum = nums[i] + nums[j];
            }
            i++;
            j--;
        }
        return minimizedmaxsum;
    }
};


// Difficulties faced(if any): coming up with light + heavy approach which will give the minimum, focus on reading constrainsts
// T.C. =  O(nlogn) + O(n/2) = O(n log n)
// S.C. = O(1) 