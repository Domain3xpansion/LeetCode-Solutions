class Solution {
public:

    vector<int> nextsmallerelementstack(vector<int> &nums1){
        int n = nums1.size();
        stack<int> st;
        st.push(n);      // If no smaller element exists to the right, it should default to 'n'
        vector<int> nse(n, 0);
        for(int i=n-1; i>=0; i--){
            while(st.top() != n && nums1[st.top()] >= nums1[i]){
                st.pop();
            }
            nse[i] = st.top();
            st.push(i);      
        }
        return nse;
    }


    vector<int> previoussmallerelemopt(vector<int> &nums1){
        int n = nums1.size();
        stack<int> st;
        st.push(-1);      // For left side, defaulting to -1 is perfect
        vector<int> pse(n, 0);
        for(int i=0; i<n; i++){
            while(st.top() != -1 && nums1[st.top()] > nums1[i]){
                st.pop();
            }
            pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) {
        // Brute force
        /*int sum = 0;
        for(int i=0; i<arr.size(); i++){
            int minn = INT_MAX;
            for(int j=i; j<arr.size(); j++){
                minn = min(minn, arr[j]);
                sum += minn;
            }
        }
        return sum;*/

        int n = arr.size(), total = 0, mod = (int)1e9 + 7;
        vector<int> nse = nextsmallerelementstack(arr);
        vector<int> pse = previoussmallerelemopt(arr);
        for(int i = 0; i < n; i++){
            int left = i - pse[i];
            int right = nse[i] - i;
            long long contribution = (right * left) % mod;
            contribution = (contribution * arr[i]) % mod;
            total = (total + contribution) % mod;
        }
        return total;
    }
};