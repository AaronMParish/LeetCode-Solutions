#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;

        function<void(int, int, string)> dfs = [&]( int l, int r, string cu ) {
            if ( l > n || r > n || l < r ) return;

            if ( l == n && r == n ) {
                res.push_back( cu );
                return;
            }

            dfs( l + 1, r, cu + "(" );

            dfs( l, r + 1, cu + ")" );
        };

        dfs( 0, 0, "" );

        return res;
    }
};