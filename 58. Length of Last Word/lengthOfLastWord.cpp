#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0,
            i = 0,
            space_index = s.length() - 1;

        while ( space_index >= 0 && s[space_index] == ' ' ) {
            space_index--;
        }

        i = space_index;

        while( i >= 0 && s[i] != ' '  ) {
            res++;
            i--;
        }

        return res;
    }
};