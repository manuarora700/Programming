// We can use map to easily solve this problem in linear time. The idea is to insert each element of the array arr[i]
// in a map. We also checks if difference (arr[i], sum-arr[i]) already
// exists in the map or not. If the difference is seen before, we print the pair and return.

#include <bits/stdc++.h>
using namespace std;

// Function to find a pair in an array with given sum using Hashing
void findPair(int arr[], int n, int sum)
{
    // create an empty map
    unordered_map<int, int> map;

    // do for each element
    for (int i = 0; i < n; i++)
    {

      //Git commit
        // check if pair (arr[i], sum-arr[i]) exists

        // if difference is seen before, print the pair
        if (map.find(sum - arr[i]) != map.end())
        {
            cout << "Pair found at index " << map[sum - arr[i]] <<
                    " and " << i;
            return;
        }

        // store index of current element in the map
        map[arr[i]] = i;
    }

    // we reach here if pair is not found
    cout << "Pair not found";
}

// main function
int main()
{
    int arr[] = { 8, 7, 2, 5, 3, 1};
    int sum = 10;

    int n = sizeof(arr)/sizeof(arr[0]);

    findPair(arr, n, sum);

    return 0;
}
