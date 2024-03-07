#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        bool sign = false;
        int ret = 0,
            i = 0,
            size = s.size();
        
        while( i < size && s[i] == ' ' )
        {
            i++;
        }
        
        if ( s[i] == '+' || s[i] == '-' )
        {
            sign = (s[i] == '-');
            i++;
        }
        
        while( i < size && isdigit(s[i]) )
        {
            if ( ret > INT_MAX / 10 || ret == INT_MAX / 10 && (s[i] - '0') > INT_MAX % 10 )
                return ( sign ? INT_MIN : INT_MAX );

            ret = ret * 10 + (s[i] - '0');
            i++;
        }

        if ( sign ) ret = -ret;
        
        return ret;
    }
};