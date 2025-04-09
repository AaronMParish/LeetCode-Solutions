#include <vector>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

        if ( digits.empty() ) return {};

        vector<string> letters = {
            "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> result = {""};

        for ( char digit : digits ) {
            string chars = letters[digit - '2'];
            vector<string> temp;

            for ( string &combination : result ) {
                for ( char ch : chars ) {
                    temp.push_back( combination + ch );
                }
            }

            result = move(temp);
        }

        return result;
    }
};