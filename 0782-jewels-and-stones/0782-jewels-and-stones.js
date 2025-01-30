/**
 * @param {string} jewels
 * @param {string} stones
 * @return {number}
 */
var numJewelsInStones = function(jewels, stones) {
    let countjewels = 0;
    for(let i = 0; i < stones.length; i++){   // T.C. for this loop: 0(n)
        if (jewels.indexOf(stones[i]) !== -1) {   // For each stone, the function calls 'jewels.indexOf(stones[i]')
            // indexOf method has a T.C of O(m), where m = length of 'jewels'
            countjewels++;
        }
    }
    return countjewels;
    // Overall T.C.: O(n*m), where n = length of 'stones' string and m = length of 'jewels' string
};