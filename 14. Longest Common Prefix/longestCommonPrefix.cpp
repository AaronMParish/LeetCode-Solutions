#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            sort( strs.begin(), strs.end() );
            string res="";
            string start = strs[0],
                    end = strs[strs.size() - 1];

            for( int i = 0; i < min(start.length(), end.length() ); i++) {
                if( start[i] == end[i] ){
                    res += start[i];
                } else {
                    break;
                }
            }

            return res;
        }
};