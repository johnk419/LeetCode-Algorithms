// Question : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> notFound(2);
        notFound = {-1, -1};
        if (nums.size() == 0) {
            return notFound;
        }
        int index = binarySearch(nums, 0, nums.size() - 1, target);
        
        if (index == -1) {
            return notFound;
        }
        int leftIndex = index;
        int rightIndex = index;
        while (nums[leftIndex] == target && leftIndex != -1) {
            leftIndex = leftIndex - 1;
        }
        while (nums[rightIndex] == target && rightIndex != nums.size()) {
            rightIndex = rightIndex + 1;
        }
        
        vector<int> result(2);
        result[0] = leftIndex + 1;
        result[1] = rightIndex - 1;
        return result;
    }
    
    int binarySearch (vector<int>& partition, int lo, int hi, int search) {
        if (hi >= lo) {
            int mid = (lo + hi) / 2;
            
            if (partition[mid] == search) {
                return mid;
            }

            if (partition[mid] > search) {
                return binarySearch(partition, lo, mid - 1, search);
            } else if (partition[mid] <= search) {
                return binarySearch(partition, mid + 1, hi, search);
            }
        
        }
        return -1;
    }
    
};