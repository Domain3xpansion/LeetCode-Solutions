class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());  // sorted by start
        vector<int> ends;
        long long count = 0;
        for(int i=0; i<intervals.size(); i++){
            int start = intervals[i][0];
            /*lower_bound finds the first position where the value is greater than or equal to start
            First previous interval whose end >= start
            
            Q. Why do we want the first >= start?
            A. Every previous interval has a start smaller than or equal to the current start because we sorted by start.
            Therefore, a previous interval intersects the current interval if:
                    previous interval's end >= current interval's start*/
            auto it = lower_bound(ends.begin(), ends.end(), start);


            /*We want no of previous intervals whose ending point is >= current interval's start
            ends.end() - it = How many elements are between it and the end?*/
            count += ends.end() - it;

            // Insert current interval's end at correct position because we have to keep ends vector sorted
            ends.insert(upper_bound(ends.begin(), ends.end(), intervals[i][1]), intervals[i][1]);
        }
        return count;
    }
};