/** Given an array of strings, return another array containing all of its longest strings.

Example

For inputArray = ["aba", "aa", "ad", "vcd", "aba"], the output should be
allLongestStrings(inputArray) = ["aba", "vcd", "aba"].

Input/Output
*/

function allLongestStrings(inputArray) {
     var largestLength = inputArray[0].length;
     
     // Iterates over the inputArray and sets the largest length accordingly
     for(var i = 1; i < inputArray.length; i++) {
          if(largestLength < inputArray[i].length) {
               largestLength = inputArray[i].length;
          }
     }
     // Uses a JS function filter() which filters out elements with the length of the largest length value. This results in inp
     inputArray = inputArray.filter((element) => {
          return element.length === largestLength;
     });
     return inputArray
}