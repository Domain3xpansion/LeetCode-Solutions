class Solution {
public:
    vector<int> nextsmallerelementstack(vector<int> &nums1){
        int n = nums1.size();
        stack<int> st;
        st.push(-1);
        vector<int> nse(n, 0);
        for(int i=n-1; i>=0; i--){
            while(st.top() != -1 && nums1[st.top()] >= nums1[i]){
                st.pop();
            }
            nse[i] = st.top();
            st.push(i); 
        }
        return nse;
    }

    vector<int> previoussmallerelementstack(vector<int> &nums1){
        int n = nums1.size();
        stack<int> st;
        st.push(-1);
        vector<int> nse(n, 0);
        for(int i=0; i<n; i++){
            while(st.top() != -1 && nums1[st.top()] >= nums1[i]){
                st.pop();
            }
            nse[i] = st.top();
            st.push(i); 
        }
        return nse;
    }

    int largestRectangleArea(vector<int>& heights) {
        int h = heights.size(), maxarea = INT_MIN;
        vector<int> pse = previoussmallerelementstack(heights);
        vector<int> nse = nextsmallerelementstack(heights);
        for(int i=0; i<h; i++){
            int l = heights[i];
            if(nse[i]<0)
                nse[i] = h;
            int b = nse[i] - pse[i] - 1;
            int area = l * b;
            maxarea = max(area, maxarea);
        }
        return maxarea;
    }
};