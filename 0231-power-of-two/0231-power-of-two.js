/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
    if(n>0 && (n & (n-1)) === 0){  
        return true;
    } else {
        return false;
    }
};