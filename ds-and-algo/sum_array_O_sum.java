import java.util.HashMap;
import java.util.Map;
import java.util.ArrayList;

class PrintallSubarrays
{
    // Utility function to insert <key, value> into the Multimap
    private static void insert(Map<Integer, ArrayList> hashMap,
                                Integer key, Integer value)
    {
        // if key is already present
        if (hashMap.containsKey(key))
            hashMap.get(key).add(value);
        else
        // key is seen for the first time
        {
            ArrayList<Integer> list = new ArrayList<Integer>();
            list.add(value);

            hashMap.put(key, list);
        }
    }

    // Function to print all sub-arrays with 0 sum present
    // in the given array
    public static void printallSubarrays(int arr[])
    {
        // n is length of the array
        int n = arr.length;

        // create an empty Multi-map to store ending index of all
        // sub-arrays having same sum
        Map<Integer, ArrayList> hashMap = new
                                    HashMap<Integer, ArrayList>();

        // insert (0, -1) pair into the map to handle the case when
        // sub-array with 0 sum starts from index 0
        insert(hashMap, 0, -1);

        int sum = 0;

        // traverse the given array
        for (int i = 0; i < n; i++)
        {
            // sum of elements so far
            sum += arr[i];

            // if sum is seen before, there exists at-least one
            // sub-array with 0 sum
            if (hashMap.containsKey(sum))
            {
                ArrayList<Integer> list = hashMap.get(sum);

                // find all sub-arrays with same sum
                for (Integer value: list) {
                    System.out.println("Subarray [" + (value + 1) + ".." +
                                                    i + "]");
                }
            }

            // insert (sum so far, current index) pair into the Multi-map
            insert(hashMap, sum, i);
        }
    }

    // main function
    public static void main (String[] args)
    {
        int A[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };

        printallSubarrays(A);
    }
}
