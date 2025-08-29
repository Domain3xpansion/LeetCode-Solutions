class Solution {
public:
    bool placeMagnets(vector<int>& position, int dist, int magnets){       
        int noofM = 1, lastM = position[0], n = position.size();
        for(int i=1; i<n; i++){   
            if(abs(position[i]-lastM) >= dist){
                noofM++;
                lastM = position[i];
            }
            if(noofM >= magnets)
                return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 0, high = position[n-1] - position[0];
        while(low <= high){
            int mid = low + (high - low)/2;
            if(placeMagnets(position, mid, m))
                low = mid + 1;           
            else
                high = mid - 1;          
        }
        return high;
    }
};