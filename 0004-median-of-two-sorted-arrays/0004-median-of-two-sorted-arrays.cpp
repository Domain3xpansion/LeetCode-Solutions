class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> combined;
        int i=0, j=0;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]) 
                combined.push_back(nums1[i++]);
            else 
                combined.push_back(nums2[j++]);
        }
        while(i<n1)
            combined.push_back(nums1[i++]);
        while(j<n2)
            combined.push_back(nums2[j++]);
        int n = n1+n2;
        if(n % 2 == 1)
            return (double)combined[n/2];
        else{
            double res = (combined[n/2]+combined[n/2-1]);
            res = res / 2;
            return res;
        }
    }
};


