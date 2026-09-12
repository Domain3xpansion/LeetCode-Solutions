class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        // Optimal
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int i = 0, j = 0;
        while(i<nums1.size() && j<nums2.size()){
            if(nums1[i] < nums2[j])
            {
                i++;
            }
            else if(nums2[j] < nums1[i])
            {
                j++;
            }
            else
            {
                if(res.empty() || res.back() != nums1[i]){
                    res.push_back(nums1[i]);
                }
                i++;
                j++;
            }
        }
        return res;
        
        // Brute force approach
        /*vector<int> intersect;
        for(int i=0; i<nums1.size(); i++){
            auto it = find(intersect.begin(), intersect.end(), nums1[i]);
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j] && it == intersect.end()){
                    intersect.push_back(nums1[i]);
                }
            }
        }
        return intersect;*/
    }
};