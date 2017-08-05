
function updateInventory(arr1, arr2) {
    // All inventory must be accounted for or you're fired!
  for(var i = 0; i < arr2.length; i++) {
    var inventoryExists = arr1.every(function(element) {
      return arr2[i][1] != element[1];
    });
    // If it doesn't exist add it to arr1, else add its stock.
    if(inventoryExists) {
      arr1.push(arr2[i]);
    }
    else
      {
        var indexVal = arr1.findIndex(function(element) {

          return element[1] === arr2[i][1];
        });
      arr1[indexVal][0] += arr2[i][0];
      }
  }
    return arr1.sort(function(a, b) {

      return a[1] < b[1] ? -1 : 1;
    });
}

// Example inventory lists
var curInv = [
    [21, "Bowling Ball"],
    [2, "Dirty Sock"],
    [1, "Hair Pin"],
    [5, "Microphone"]
];

var newInv = [
    [2, "Hair Pin"],
    [3, "Half-Eaten Apple"],
    [67, "Bowling Ball"],
    [7, "Toothpaste"]
];

updateInventory(curInv, newInv);
