#include <cstdlib>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if ( x < 0 )
            return false;

        int original_num = x;
        long reverse_num = 0;

        while ( x > 0 )
        {
            reverse_num = reverse_num * 10 + x % 10;
            x = floor(x / 10);
        }

        return reverse_num == original_num;
    }
};