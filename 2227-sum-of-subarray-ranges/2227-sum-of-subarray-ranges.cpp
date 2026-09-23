class Solution {
public:
    vector<int> nextgreaterelement(vector<int> &nums1){
        int n = nums1.size();
        stack<int> st;
        st.push(n); 
        vector<int> nse(n, 0);
        for(int i=n-1; i>=0; i--){
            while(st.top() != n && nums1[st.top()] <= nums1[i]){
                st.pop();
            }
            nse[i] = st.top();
            st.push(i);      
        }
        return nse;
    }


    vector<int> previousgreaterelem(vector<int> &nums1){
        int n = nums1.size();
        stack<int> st;
        st.push(-1);  
        vector<int> pse(n, 0);
        for(int i=0; i<n; i++){
            while(st.top() != -1 && nums1[st.top()] < nums1[i]){
                st.pop();
            }
            pse[i] = st.top();
            st.push(i);
        }
        return pse;
    }

    vector<int> nextsmallerelement(vector<int> &nums1){
        int n = nums1.size();
        stack<int> st;
        st.push(n);
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

    vector<int> previoussmallerelem(vector<int> &nums1){
        int n = nums1.size();
        stack<int> st;
        st.push(-1);
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

    long long subArrayRanges(vector<int>& nums) {
        /* brute force
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            int largest = INT_MIN, smallest = INT_MAX;
            for(int j=i; j<n; j++){
                if(nums[j]>largest)
                    largest = nums[j];
                if(nums[j]<smallest)
                    smallest = nums[j];
                sum = sum + largest - smallest;
            }
        }
        return sum;*/
        long long n = nums.size(), total = 0, totalmax = 0;
        vector<int> nse = nextsmallerelement(nums);
        vector<int> pse = previoussmallerelem(nums);
        vector<int> nge = nextgreaterelement(nums);
        vector<int> pge = previousgreaterelem(nums);
        for(int i = 0; i < n; i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            long long leftmax = i - pge[i];
            long long rightmax = nge[i] - i;
            long long contribution = right * left * nums[i];
            long long contributionmax = leftmax * rightmax * nums[i];
            total += contribution;
            totalmax += contributionmax;
        }
        return totalmax - total;
    }
};