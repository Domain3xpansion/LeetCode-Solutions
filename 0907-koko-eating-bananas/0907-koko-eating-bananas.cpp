class Solution {
public:
    long calc_time(vector<int> piles, long mid){
        int n = piles.size();
        long hour = 0;
        for(int i=0; i<n; i++){
            hour += ceil((double)piles[i]/(double)mid);
        }
        return hour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        auto max_it = std::max_element(piles.begin(), piles.end());
        int low = 1, high = *max_it;
        while(low <= high){
            long mid = low + (high - low)/2;
            long hours = calc_time(piles, mid);
            if(hours <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};