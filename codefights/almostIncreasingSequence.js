/*
Given a sequence of integers as an array, determine whether it is possible to obtain a strictly increasing sequence by removing no more than one element from the array.

Example

For sequence = [1, 3, 2, 1], the output should be
almostIncreasingSequence(sequence) = false;

There is no one element in this array that can be removed in order to get a strictly increasing sequence.

For sequence = [1, 3, 2], the output should be
almostIncreasingSequence(sequence) = true.

You can remove 3 from the array to get the strictly increasing sequence [1, 2]. Alternately, you can remove 2 to get the strictly increasing sequence [1, 3].

Input/Output

[time limit] 4000ms (js)
[input] array.integer sequence

Guaranteed constraints:
2 ≤ sequence.length ≤ 105,
-105 ≤ sequence[i] ≤ 105.

[output] boolean

Return true if it is possible to remove one element from the array in order to get a strictly increasing sequence, otherwise return false.


*/

function almostIncreasingSequence(sequence) {
var currentValue = sequence[0];
var position = 0;
if(checkArray(removeNumber(0,sequence))==true){
return true;
}
for(var i=1;i<sequence.length-1;i++){

    //Start decrease point so we only choose to delete this number or next number
    //Check when (Delete this number if next number > currentValue)
    //Check when (Delete next number if next number <= currentValue)
    if(sequence[i]>=sequence[i+1] && sequence[i+1]>currentValue){
        position=i;
        //After delete, let see if array is increase or not
        if(checkArray(removeNumber(position,sequence))==true){
            return true;
        }
        else{
            return false;
        }
    }
    else if(sequence[i]>=sequence[i+1] && sequence[i+1]<=currentValue){
        position=i+1;
        //After delete, let see if array is increase or not
        if(checkArray(removeNumber(position,sequence))==true){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    currentValue= sequence[i];
}
return false;
}

//Function to check if one array is increase or not. example : 1,2,5 or 3,4,6
function checkArray(arrayInput){
for(var i=0;i<arrayInput.length-1;i++){
if(arrayInput[i]>=arrayInput[i+1]){
return false;
}
}
return true;
}

//remove one elements at position in array and return array without that element
function removeNumber(position,arrayInput){
var newArray = new Array();
var count=0;
for(var i=0;i<arrayInput.length;i++){
if(i==position){
continue;
}
else{
newArray[count]=arrayInput[i];
count++
}
}
return newArray;
}
