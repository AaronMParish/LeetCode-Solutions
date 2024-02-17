#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if ( numRows == 1 )
            return s;

        vector<string> rows(numRows, "");
        string ans;
        int row = 0,
            dir = 1;

        for( auto c : s )
        {
            rows[row] += c;
            if ( dir == 1 )
            {
                if ( row >= numRows - 1 )
                    dir = -1;
            }
            else if ( row <= 0 )
                dir = 1;

            row += dir;
        }

        for( auto v : rows )
            ans += v;

        return ans;
    }
};