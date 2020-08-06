/*

requirements

1880. Largest Number X Which Occurs X Times
Given an array A consisting of N integers, you should return the biggest value X, which occurs in A exactly X times. If there is no such value, you should return 0.

Example
Example 1:
Input: [3, 8, 2, 3, 3, 2]
Output: 3
Explanation: The value 2 occurs exactly two times and the value 3 occurs exactly three times. Meanwhile, the maximum of 2 and 3 is 3 so the answer is 3.

Example 2:
Input: [3, 1, 4, 1, 5]
Output: 0
Explanation: There is no value which meets the task conditions so the answer is 0.

Notice
N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000].
*/

class Solution {
public:
    /**
     * @param arr: an array of integers
     * @return: return the biggest value X, which occurs in A exactly X times.
     */
    int findX(vector<int> &arr) {
        // write your code here
        unordered_map<int, int> hashMap;
        for (size_t i = 0; i < arr.size(); ++i)
        {
            if (hashMap.count(arr[i]))
                ++hashMap[arr[i]];
            else hashMap[arr[i]] = 1;
        }
        int X = 0;
        for (auto&& elem: hashMap)
        {
            if (elem.first == elem.second)
                X = max(elem.first, X);
        }
        return X;
    }
};