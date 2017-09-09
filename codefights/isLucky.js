// Ticket numbers usually consist of an even number of digits. A ticket number is considered lucky if the sum of the first half of the digits is equal to the sum of the second half.
//
// Given a ticket number n, determine if it's lucky or not.
//
// Example
//
// For n = 1230, the output should be
// isLucky(n) = true;
// For n = 239017, the output should be
// isLucky(n) = false.

function isLucky(n) {
    n = n.toString();

    let half = n.length/2;

    let firstHalf = n.substring(0, half).split("").reduce((a,b)=>{
        return parseInt(a) + parseInt(b);
    });

    let secondHalf = n.substring(half, n.length).split("").reduce((a,b)=>{
        return parseInt(a) + parseInt(b);
    });
    return firstHalf === secondHalf;
}
