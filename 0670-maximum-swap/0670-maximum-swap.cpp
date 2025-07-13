class Solution {
public:
    int maximumSwap(int num) {
        string str_equiv = to_string(num);
        int n = str_equiv.size();
        vector<int> max_right(n, 0);
        max_right[n-1] = n-1;
        for(int i=n-2; i>=0; i--){
            int ind = max_right[i+1];
            int elem = str_equiv[ind];
            max_right[i] = (str_equiv[i] > elem) ? i : ind;
        }
        for(int i=0; i<n; i++){
            int ind = max_right[i];
            int elem = str_equiv[ind];
            if(str_equiv[i]<elem){
                swap(str_equiv[i], str_equiv[ind]);
                return stoi(str_equiv);
            }
        }
        return num;
    }
};