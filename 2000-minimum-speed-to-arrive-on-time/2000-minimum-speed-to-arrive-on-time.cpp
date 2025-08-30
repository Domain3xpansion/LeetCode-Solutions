class Solution {
public:
    double timetaken(vector<int>& dist, long mid){
        double t = 0;
        int n = dist.size();
        for(int i = 0; i < n; ++i){
            double time = (double)dist[i] / mid;
            if(i != n - 1)
                t += ceil(time);
            else
                t += time;
        }
        return t;
    }


    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour <= dist.size() - 1)
            return -1;
        int low = 1, high = 1e7;
        while(low <= high){
            long mid = low + (high - low)/2;
            double time = timetaken(dist, mid);
            if(time<=hour)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};