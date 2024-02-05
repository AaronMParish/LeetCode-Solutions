class Solution {
public:
    // Fills string with special character '#' 
    // to make string even. (Note: New size = N*2 + 1)
    string fillString(const string s) {
        string temp = "$";

        for( char c : s )
            temp += string(1, c) + '#';

        temp = temp.substr(0, temp.size() - 1) + "@";

        return temp;
    }

    string longestPalindrome(string s) {
        string ans,
               str = fillString(s);

        size_t size = str.size();

        int start = 0,  //iteration from center
            c = 0,  //center letter of palindrome
            r = 0,  //rightmost boundary of palindrome
            max = 0;//highest palindrome found so far   

        //max palindrome of each starting location is stored.
        vector<int> p(size, 0);

        //for each excluding first and last chars ('$' and '@')
        for ( int i = 1; i < size - 1; i++ ) {
            p[i] = 1;

            if ( i < r ) {
                p[i] = min(r - i, (2 * c - i >= 0) ? p[2 * c - i] : 0);
            }


            char minc = ((i - p[i] >= 0 ) ? str[i - p[i] ] : '1'),
                 pluc = ((i + p[i] < size) ? str[i + p[i]] : '0');
 
            while ( pluc == minc ) {
                p[i]++;
                minc = ((i - p[i] >= 0 ) ? str[i - p[i]] : '1');
                pluc = ((i + p[i] < size) ? str[i + p[i]] : '0');
            }

            if ( i + p[i] > r ) {
                c = i;
                r = i + p[i];
            }
            
            if ( p[i] > max ) {
                start = (i - p[i]);
                max = p[i];
            }
        }

        start = (start + 1) / 2;

        for( int i = start; i <= start + max - 2; i++ )
            ans += s[i];

        return ans;
    }
};