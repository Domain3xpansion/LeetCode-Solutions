class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=m-1; i>=0; --i){   // Shifting nums1 elements to the end of the same array
            nums1[i+n] = nums1[i];   // for loop takes 
        } // Shifting takes O(m)
        int i=n, j=0, k=0; 
        while(k<m+n){
            if (j>=n || (i<m+n && nums1[i] <= nums2[j])) {  // j>=n becauuse it means all elements in nums2 have 
            // been processed, and there are no more elements left to merge from nums2 array.  
                nums1[k++] = nums1[i++];     // Move element from shifted nums1
            }else{
                nums1[k++] = nums2[j++];     // Move element from nums2
            }
        }
        // while loop takes O(m + n)
    }
};


// Total Time Complexity = O(m) + O(m+n) = O(m+n)

