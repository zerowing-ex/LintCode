/*

requirements

1394. Goat Latin
A sentence S is given, composed of words separated by spaces. Each word consists of lowercase and uppercase letters only.

We would like to convert the sentence to "Goat Latin" (a made-up language similar to Pig Latin.)

The rules of Goat Latin are as follows:

If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.

For example, the word 'apple' becomes 'applema'.

If a word begins with a consonant (i.e. not a vowel), remove the first letter and append
it to the end, then add "ma".
For example, the word "goat" becomes "oatgma".

Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
Return the final sentence representing the conversion from S to Goat Latin.

Example
Example1

Input: "I speak Goat Latin"
Output: "Imaa peaksmaaa oatGmaaaa atinLmaaaaa"
Example2

Input: "The quick brown fox jumped over the lazy dog"
Output: "heTmaa uickqmaaa rownbmaaaa oxfmaaaaa umpedjmaaaaaa overmaaaaaaa hetmaaaaaaaa azylmaaaaaaaaa ogdmaaaaaaaaaa"
Notice
S contains only uppercase, lowercase and spaces. Exactly one space between each word.
1 <= S.length <= 150.

*/

class Solution {
public:
    /**
     * @param S: 
     * @return: nothing
     */
    string  toGoatLatin(string &S) {
        unordered_set<char> vowels( {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'} );
        istringstream iss(S);
        string res, w;
        string append = "a";
        while (iss >> w)
        {
            res += ' ' + (vowels.count(w[0])? w : w.substr(1) + w[0]) + "ma";
            res += append;
            append += "a";
        }
        return res.substr(1);
    }
};