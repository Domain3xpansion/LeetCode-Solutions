/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function(n) {
    let fb = [];
    let i = 1;
    while(i <= n){
        if(i % 15 == 0){
            fb.push("FizzBuzz");
        }
        else if(i % 3 == 0){
            fb.push("Fizz");
        }
        else if(i % 5 == 0){
            fb.push("Buzz");
        }
        else{
            fb.push(i.toString());
        }
        i++;
    }
    return fb;
};