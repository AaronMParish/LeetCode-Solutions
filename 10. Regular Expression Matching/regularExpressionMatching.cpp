#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length(), p_len = p.length();
        vector<vector<bool>> sol(s_len + 1, vector<bool>(p_len + 1, false));

        sol[0][0] = true;

        for( int j = 1; j <= p_len; j++ ) {
            if ( p[j - 1] == '*' ) {
                sol[0][j] = sol[0][j - 2];
            }
        }

        for ( int i = 1; i <= s_len; i++ ) {
            for ( int j = 1; j <= p_len; j++ ) {
                if( p[j - 1] == s[i - 1] || p[j - 1] == '.' ) {
                    sol[i][j] = sol[i - 1][j - 1];
                } else if ( p[j - 1] == '*' ) {
                    sol[i][j] = sol[i][j - 2];
                    if ( p[j - 2] == s[i - 1] || p[j - 2] == '.' ) {
                        sol[i][j] = sol[i][j] | sol[i - 1][j];
                    }
                } else {
                    sol[i][j] = false;
                }
            }
        }

        return sol[s_len][p_len];
    }
};