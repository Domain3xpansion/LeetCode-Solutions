class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1); 
        int low = 0, high = n1;
        int cut1, cut2, l1, l2, r1, r2;
        while(low <= high) {
            cut1 = low + (high - low) / 2;
            cut2 = ((nums1.size() + nums2.size() + 1) / 2) - cut1;
            l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            r1 = (cut1 == n1) ? INT_MAX : nums1[cut1];
            r2 = (cut2 == n2) ? INT_MAX : nums2[cut2];
            if(l1 > r2)
                high = cut1 - 1;
            else if(l2 > r1)
                low = cut1 + 1;
            else
                return (n1 + n2) % 2 == 0 ? (double)(max(l1, l2) + min(r1, r2)) / 2.0 : (double)max(l1, l2);
        }
        return 0.0; 
        /*
        int n1 = nums1.size(), n2 = nums2.size(), n;
        n = n1 + n2;
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
        if(n % 2 == 1)
            return (double)combined[n/2];
        else{
            double res = (combined[n/2]+combined[n/2-1]);
            res = res/2;
            return res;
        }
        */
    }
};


//Brute force solution
//T.C = O(n1+n2)
//S.C = O(n1+n2) because size of the combined array is n1+n2