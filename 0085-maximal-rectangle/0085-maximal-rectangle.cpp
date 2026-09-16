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
    int maximalRectangle(vector<vector<char>>& matrix){
        int rows = matrix.size(), cols = matrix[0].size(), maxArea = INT_MIN;
        vector<vector<int>> prefix_sum(rows, vector<int>(cols, 0));
        for(int j=0; j<cols; j++){
            int sum = 0;
            for(int i=0; i<rows; i++){
                sum += matrix[i][j] - '0';
                if(matrix[i][j] - '0' == 0)
                    sum = 0;
                prefix_sum[i][j] = sum;
            }
        }
        for(int i=0; i<rows; i++){
            maxArea = max(maxArea, largestRectangleArea(prefix_sum[i]));
        }
        return maxArea;
    }
};