class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> intersect;
        for(int i=0; i<nums1.size(); i++){
            auto it = find(intersect.begin(), intersect.end(), nums1[i]);
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j] && it == intersect.end()){
                    intersect.push_back(nums1[i]);
                }
            }
        }
        return intersect;
    }
};