/*

requirements

1199. Perfect Number
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.

Example
Example:

Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Notice
The input number n will not exceed 100,000,000
*/

class Solution {
public:
    /**
     * @param num: an integer
     * @return: returns true when it is a perfect number and false when it is not
     */
    bool checkPerfectNumber(int num) {
        // write your code here
        if (num == 1)
            return false;
        int sum = 1;
        for (long long i = 2; i * i <= num; ++i)
        {
            if (!(num % i))
            {
                if (i * i == num)
                    sum += i;
                else
                    sum += i + num / i;
            }
            if (sum > num)
                return false;
        }
        return num == sum;
    }
};