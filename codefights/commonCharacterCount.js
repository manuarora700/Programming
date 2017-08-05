/**
 * Given two strings, find the number of common characters between them.

Example

For s1 = "aabcc" and s2 = "adcaa", the output should be
commonCharacterCount(s1, s2) = 3.

Strings have 3 common characters - 2 "a"s and 1 "c".
*/
function commonCharacterCount(s1, s2) {
    // Split up the strings into arrays.
    
    s1 = s1.split("");
    s2 = s2.split("");
    // Create empty objects
    var s1Object ={};
    var s2Object = {};
    
    // 2 for loops to iterate over s1 first and checks if s1 has a property that we are looking for.
    for(var i = 0; i < s1.length; i++) {
        if(s1Object.hasOwnProperty(s1[i]) === false) {
            s1Object[s1[i]] = 1;
        }
        else {
            s1Object[s1[i]]++;
        }
    }
    
    for(var i = 0; i < s2.length; i++) {
        if(s2Object.hasOwnProperty(s2[i]) === false) {
            s2Object[s2[i]] = 1;
        }
        else {
            s2Object[s2[i]]++;
        }
    }
    
    var total = 0;
    for(var prop in s1Object) {
        if(s2Object.hasOwnProperty(prop)===true) {
            
            if(s2Object[prop] < s1Object[prop]) {
                total += s2Object[prop];
            }
            else{
                total += s1Object[prop];
            }
            
        }
    }
    
    return total;
}
