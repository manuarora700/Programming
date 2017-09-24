#include <iostream>
#include <unordered_map>
using namespace std;

// Function to print all sub-arrays with 0 sum present
// in the given array
void printallSubarrays(int arr[], int n)
{
    // create an empty multi-map to store ending index of all
    // sub-arrays having same sum
    unordered_multimap<int, int> map;

    // insert (0, -1) pair into the map to handle the case when
    // sub-array with 0 sum starts from index 0
    map.insert(pair<int, int>(0, -1));

    int sum = 0;

    // traverse the given array
    for (int i = 0; i < n; i++)
    {
        // sum of elements so far
        sum += arr[i];

        // if sum is seen before, there exists at-least one
        // sub-array with 0 sum
        if (map.find(sum) != map.end())
        {
            auto it = map.find(sum);

            // find all sub-arrays with same sum
            while (it != map.end() && it->first == sum)
            {
                cout << "Subarray [" << (it->second + 1) << ".." << i <<
                        "]\n";
                it++;
            }
        }

        // insert (sum so far, current index) pair into multi-map
        map.insert(pair<int, int>(sum, i));
    }
}

// main function
int main()
{
    int arr[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
    int n = sizeof(arr)/sizeof(arr[0]);

    printallSubarrays(arr, n);

    return 0;
}
