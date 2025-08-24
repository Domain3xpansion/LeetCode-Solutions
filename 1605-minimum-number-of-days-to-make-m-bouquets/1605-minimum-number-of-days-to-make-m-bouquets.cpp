class Solution {
public:
    int calc_bou(long mid, int k, vector<int>& bloomDay){
        int adj_flowers = 0, bou = 0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i] <= mid){
                adj_flowers++;
                if(adj_flowers == k){
                    bou++;
                    adj_flowers = 0;
                }
            }else
                adj_flowers = 0;
        }
        return bou;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        int n = bloomDay.size();
        if((long long)m*k > n)
            return -1;
        while(low <= high){
            long mid = low + (high - low)/2;
            int num_bou = calc_bou(mid, k, bloomDay);
            if(num_bou >= m)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};