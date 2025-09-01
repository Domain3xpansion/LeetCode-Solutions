class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), i=0, j=0;
        int n = n1 + n2;
        vector<int> ans;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j])
                ans.push_back(nums1[i++]);
            else
                ans.push_back(nums2[j++]);
        }
        while(i<n1)
            ans.push_back(nums1[i++]);
        while(j<n2)
            ans.push_back(nums2[j++]);  
        if(n%2 == 1)
            return ans[n/2];
        return (double)((double)(ans[n/2]) + (double)(ans[n/2-1]))/2.0;
    }
};