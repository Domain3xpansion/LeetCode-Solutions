class Solution {
public:
    int capacity_cal(vector<int>& weights, long mid){
        int d_sum = 0, d = 1;
        for(int w: weights){
            if(d_sum + w > mid){
                d++;
                d_sum = 0;
            }
            d_sum += w;
        }
        return d;
    }
    int summation(vector<int>& weights){
        int summ = 0;
        for(int x: weights){
            summ += x;
        }
        return summ;
    }
    int shipWithinDays(vector<int>& weights, int days){
        int low = *max_element(weights.begin(), weights.end()), high = summation(weights);
        while(low <= high){
            long mid = low + (high - low)/2;
            int days_taken = capacity_cal(weights, mid);
            if(days_taken <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};