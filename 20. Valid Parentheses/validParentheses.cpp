#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> open;

        for ( auto c : s ) {
            switch( c ) {
                case '(':
                    open.push(c);
                break;
                case '[':
                    open.push(c);
                break;
                case '{':
                    open.push(c);
                break;
                case ')':
                    if ( !open.empty() && open.top() == '(' ) {
                        open.pop();
                    } else return false;
                break;
                case ']':
                    if ( !open.empty() && open.top() == '[' ) {
                        open.pop();
                    } else return false;
                break;
                case '}':
                    if ( !open.empty() && open.top() == '{' ) {
                        open.pop();
                    } else return false;
                break;
            }
        }

        return open.empty();
    }
};