#include <string>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int base[] = {1000, 100, 10, 1};
        char sym[] = {'M', 'C', 'X', 'I'};
        char sym5[] = {'D', 'L', 'V'};
        string res = "";

        for ( int i = 0; i < 4; i++ ) {
            int num_div = num / base[i];
            int num_5 = num_div / 5;
            num -= base[i] * num_div;

            if ( num_div == 9 ) {
                res += sym[i];
                res += sym[i - 1];
                num_div -= 9;
            } else if ( num_5 ) { 
                res += sym5[i - 1];
                num_div -= 5; 
            } else if ( num_div == 4 ) {
                res += sym[i];
                res += sym5[i - 1];
                num_div -= 4;
            }

            while( num_div > 0 ) {
                res += sym[i];
                num_div--;
            }
        }

        return res;
    }
};