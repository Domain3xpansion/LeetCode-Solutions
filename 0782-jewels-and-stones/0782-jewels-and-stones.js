/**
 * @param {string} jewels
 * @param {string} stones
 * @return {number}
 */
var numJewelsInStones = function(jewels, stones) {
    let countjewels = 0;
    for(let i = 0; i < stones.length; i++){   // t.c.
        if (jewels.indexOf(stones[i]) !== -1) {
            countjewels++;
        }
    }
    return countjewels;
};