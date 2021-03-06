/*
中文English
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example
Example 1:
	Input:  [[5]],2
	Output: false
	
	Explanation: 
	false if not included.
	
Example 2:
	Input:  [
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
],3
	Output: true
	
	Explanation: 
	return true if included.
Challenge
O(log(n) + log(m)) time
*/

class Solution {
public:
    /**
     * @param matrix: matrix, a list of lists of integers
     * @param target: An integer
     * @return: a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        // write your code here
        //line
        if(matrix.empty() || matrix[0].empty())   
       {  
          return false;  
       } 
        int row=0;  
        int col=matrix[0].size()-1;  
        while(row<matrix.size() && col>-1){  
            if(matrix[row][col]==target){  
                return true;
            }else if(matrix[row][col] > target){  
                col--;  
            }else{  
                row++;  
            }  
        }
        return false;
    }
};
