class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0, //left side of sliding window
            end = 0,   //right side of sliding window
            max = 0;   //max length found
        unordered_set<char> charSet;

        while( end < s.size() )
        {
            if( charSet.find(s[end]) == charSet.end() )
            {
                charSet.insert( s[end] );
                end++;
                if ( end - start > max )
                    max = end - start;
            }
            else
            {
                charSet.erase( s[start] );
                start++;
            }
        }
        
        return max;
    }
};