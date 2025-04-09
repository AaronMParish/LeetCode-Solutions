#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result = {};
        int size = nums.size();

        if ( size < 4 ) {
            return result;
        }

        //sort in increasing order
        sort(nums.begin(), nums.end());

        //first pointer, i < size - 4 to leave room for other three pointers
        for ( int i = 0; i < size - 3; ++i ) {
            if ( i > 0 && nums[i] == nums[i - 1] ) {
                continue;
            }

            //second pointer, j < size - 3 to leave room for next two pointers
            for ( int j = i + 1; j < size - 2; ++j ) {
                if ( j > i + 1 && nums[j] == nums[j - 1] ) {
                    continue;
                }

                //left and right are set at edges of available indeces
                int left = j + 1,
                    right = size - 1;

                while ( left < right ) {
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[left] + nums[right];

                    if ( sum < target ) {
                        ++left;
                    } else if ( sum > target ) {
                        --right;
                    } else {
                        result.push_back( { nums[i], nums[j], nums[left], nums[right] } );

                        --right;
                        ++left;

                        while ( left < right && nums[right + 1] == nums[right] ) {
                            --right;
                        }

                        while ( left < right && nums[left - 1] == nums[left] ) {
                            ++left;
                        }
                    }
                }
            }
        }

        return result;
    }
};