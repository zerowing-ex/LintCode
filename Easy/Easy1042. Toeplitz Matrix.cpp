/*

requriements

1042. Toeplitz Matrix
A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same element.

Now given an M x N matrix, return True if and only if the matrix is Toeplitz.

Example
Example 1:

Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
Output: True
Explanation:
1234
5123
9512

In the above grid, the diagonals are "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]", and in each diagonal all elements are the same, so the answer is True.


Example 2:

Input: matrix = [[1,2],[2,2]]
Output: False
Explanation:
The diagonal "[1, 2]" has different elements.
Notice
matrix will be a 2D array of integers.
matrix will have a number of rows and columns in range [1, 20].
matrix[i][j] will be integers in range [0, 99].
*/

class Solution {
public:
    /**
     * @param matrix: the given matrix
     * @return: True if and only if the matrix is Toeplitz
     */
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        // Write your code here
        for(int row = matrix.size() - 1; row >= 0; --row)
        {
            for(int col = matrix[0].size() - 1; col >= 0; --col)
            {
                if(row-1 >= 0 && col-1 >= 0 &&
                matrix[row][col] != matrix[row-1][col-1])
                    return false;
            }
        }
        return true;
    }
};