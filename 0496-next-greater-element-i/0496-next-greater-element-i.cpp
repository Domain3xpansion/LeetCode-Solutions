class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // Brute force
        /*vector<int> res;
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
        return res;*/
        vector<int> res, nge(nums2.size(), 0);     // nge stores the next greater element of every position in nums2
        stack<int> st;
        for(int i = nums2.size() - 1; i >= 0; i--){   
            while(!st.empty() && st.top() <= nums2[i])
            st.pop();
            if(st.empty())
                nge[i] = -1;
            else
                nge[i] = st.top();
            st.push(nums2[i]);
        }
        for(int x : nums1){        // O(n1 Ã n2)
            auto it = find(nums2.begin(), nums2.end(), x);
            int pos = it - nums2.begin();
            res.push_back(nge[pos]);
        }
        return res;
    }
};