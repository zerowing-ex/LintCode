/*

requirements

1193. Detect Capital
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "lintcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.

Example
Example 1:

Input: "USA"
Output: True
Example 2:

Input: "FlaG"
Output: False
Notice
The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

class Solution {
public:
    /**
     * @param word: a string
     * @return: return a boolean
     */
    bool detectCapitalUse(string &word) {
        // write your code here
        if (word.empty()) return false;
        size_t m = word.length();
        int cntuppers = 0, cntlowers = 0;
        for (size_t i = 0; i < m; ++i)
        {
            if (isupper(word[i]))
                ++cntuppers;
            if (islower(word[i]))
                ++cntlowers;
        }
        return (cntlowers == m) || (cntuppers == m) || (cntlowers + 1 == m && isupper(word[0]));
    }
};