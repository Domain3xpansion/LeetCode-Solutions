class Solution {
public:
    bool isPossible(vector<int>& quantities, int n, int mid){
        int stores_needed = 0;
        for(int x : quantities){
            stores_needed += ceil((double)x / mid);
        }
        if(stores_needed <= n)
            return true;
        else
            return false;
    }
    
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        while(low <= high){
            int mid = low + (high - low)/2;
            if(isPossible(quantities, n, mid))
                high = mid - 1;
            else
                low = mid + 1;     
        }
        return low;
    }
};