class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> visit;
        while(n!=1){     //checking if 'n' is 1 as an input, without doing too much calculation, return true OR if  
        // n becomes 1 in the process itself, return true 
            if(visit.find(n) != visit.end()){       
                return false;            
            }                       
            /*
            //if condition will be true only if we find out that there is already a number present 
            in the hash set which is equal to that number currently we are handling (loops endlessly in a cycle
            which does not include 1.)And therefore, it will go inside of that if block and return false because 
            that is not a happy number. The if condition will evaluate to false if no such element is available in 
            the hash set because find returns an iterator to the end of the set and visit.end() != visit.end() will 
            evaluate to false.
            */
            visit.insert(n);       // put the value of 'n' in the hash set
            int sum = 0;
            while(n>0){
                int digit = n % 10;    // take remainder, sqaure it and update it to 'sum' variable
                sum += digit * digit;
                n /= 10;
            }
            n = sum;        // update 'n' with the value which is present in 'sum' variable
        }
        return true;
    }
};