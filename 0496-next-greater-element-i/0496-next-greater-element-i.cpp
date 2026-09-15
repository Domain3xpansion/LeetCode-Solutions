class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Brute force
        vector<int> res;
        for(int i=0; i<nums1.size(); i++){
            auto it = find(nums2.begin(), nums2.end(), nums1[i]);
            if(it != nums2.end()){
                int pos = it - nums2.begin();
                bool found = false;
                for(int j=pos+1; j<nums2.size(); j++){
                    if(nums2[j] > nums1[i]){
                        res.push_back(nums2[j]);
                        found = true;
                        break;
                    }
                }
                if(!found)
                    res.push_back(-1);
                }
        }
        return res;
    }
};