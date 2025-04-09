#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest_sum = 0,
            min_diff = INT_MAX,
            size = nums.size();

        for( int i = 0; i < size - 2; ++i ) {
            int left = i + 1,
                right = size - 1;

            while( left != right ) {
                int current_sum = nums[i] + nums[left] + nums[right];
                int current_diff = abs(current_sum - target);

                if ( current_sum == target )
                    return current_sum;

                if ( current_diff < min_diff ) {
                    closest_sum = current_sum;
                    min_diff = current_diff;
                }

                if ( current_sum < target ) {
                    ++left;
                }

                if ( current_sum > target ) {
                    --right;
                }
            }
        }

        return closest_sum;
    }
};