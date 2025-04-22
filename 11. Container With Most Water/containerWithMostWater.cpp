#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0,
            j = height.size()-1,
            maxArea = INT_MIN,
            currMax = INT_MIN;

        while( i < j ) {
            currMax = min(height[i], height[j]) * (j - i);
            maxArea = max(currMax, maxArea);

            if ( height[i] < height[j] ) {
                int currIdx = i;

                while( i < j && height[currIdx] >= height[i] )
                    i += 1;
            } else {
                int currIdx = j;

                while( i < j && height[currIdx] >= height[j] )
                    j -= 1;
            }
        }
    
        return maxArea;
    }
};