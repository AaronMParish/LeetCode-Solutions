class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        //script uses smallest list for algorithm
        if (nums2.size() < nums1.size())
            return findMedianSortedArrays(nums2, nums1);

        int size1 = nums1.size(),   //size of smallest list
            size2 = nums2.size(),   //size of largest list
            start = 0,              //start of binary search range
            end = size1,            //end of binary search range
            partitionA = 0,         //pivot point for nums1
            partitionB = 0,         //pivot point for nums2
            maxLeftA = 0,           // These four vars check values beside pivot
            minRightA = 0,          // ie:
            maxLeftB = 0,           // [x] | [] 
            minRightB = 0;          // [] | [x]

        //run loop until match is found
        while (start <= end)
        {
            /*
            We find where to place the partition in both nums1 and nums2.
            Each time we dont find valid median, remove half of nums1 from selection
            partitionA (nums1) = 0 - nums1.size
            partitionB (nums2) is size of both arrays / 2 - partitionA.
            max/min A and B are the two numbers on each side of the partition.
                We want to find if nums1.left < nums2.right and nums2.left < nums1.right
                    nums1  w | x
                    nums2  y | z
                    w < z, y < x
                if we find the correct partitions, we can find the median from w, x, y, z.
            */
            partitionA = (start + end) / 2,
                partitionB = (size1 + size2 + 1) / 2 - partitionA,
                maxLeftA = (partitionA <= 0) ? INT_MIN : nums1[partitionA - 1];
            minRightA = (partitionA >= size1) ? INT_MAX : nums1[partitionA];
            maxLeftB = (partitionB <= 0) ? INT_MIN : nums2[partitionB - 1];
            minRightB = (partitionB >= size2) ? INT_MAX : nums2[partitionB];

            // Median found
            if (maxLeftA <= minRightB && maxLeftB <= minRightA)
            {
                //if the merged array's size is even
                if ((size1 + size2) % 2 == 0)
                {
                    //find average between the two middle values
                    return (min(minRightA, minRightB) + max(maxLeftA, maxLeftB)) / 2.0;
                }
                else
                {
                    //return highest middle
                    return max(maxLeftA, maxLeftB);
                }
            } //if median hasnt been found, cut off half of an array
            else if (maxLeftA > maxLeftB)
            {
                end = partitionA - 1;
            }
            else
            {
                start = partitionA + 1;
            }
        }

        return -1;
    }
};