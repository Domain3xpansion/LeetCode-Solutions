class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int i = 0, j = people.size() - 1, count = 0;
        std::sort(people.begin(), people.end());      // O(nlogn)
        while(i<=j){     // Loop runs till O(n)
            if(people[i] + people[j] <= limit){
                i++;
            }
            j--;
            count++;
        }
        return count;
    }
};

// Difficulties faced(if any): coming up with light + heavy approach which will give the minimum, focus on reading constrainsts
// T.C. =  O(nlogn) + O(n) = O(n log n)
// S.C. = O(1) 
