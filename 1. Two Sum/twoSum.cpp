#include <unordered_map>

class twoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //create a hashtable that will store <integer value, array index>
        std::unordered_map<int, int> hashTable;
        vector<int> result{0, 0};

        //iterate through all integers to find sum pair
        for( int i = 0; i < nums.size(); i++ )
        {
            //if hash table contains target number MINUS current number (target = nums[i] + x)
            if (auto search = hashTable.find(target - nums[i]); search != hashTable.end())
            {
                //return results if pair is found in table
                result[0] = search->second;
                result[1] = i;
                break;
            }
            else
            {
                //if x does not exist in table, add current number to table and continue
                hashTable.insert({nums[i], i});
            }
        }

        return result;
    }
};