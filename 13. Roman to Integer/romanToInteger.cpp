#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<string, int> roman_int = {
            {"I", 1},
            {"IV", 4},
            {"V", 5},
            {"IX", 9},
            {"X", 10},
            {"XL", 40},
            {"L", 50},
            {"XC", 90},
            {"C", 100},
            {"CD", 400},
            {"D", 500},
            {"CM", 900},
            {"M", 1000},
        };

        int i = s.length() - 1,
            res = 0;

        while( i >= 0 ) {
            string check = "";
            int value = 0;

            if ( i > 0 )
                check = s.substr(i - 1, 2);
            else
                check = s[i];
            
            if ( roman_int.find(check) != roman_int.end() )
            { 
                value = roman_int[check];
                i -= 2;
            }
            else
            {
                check = s[i];
                value = roman_int[check];
                i--;
            }

            res += value;
        }

        return res;
    }
};