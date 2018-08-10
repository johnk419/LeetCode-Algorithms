// Question : https://leetcode.com/problems/maximum-subarray/description/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxCurr = nums[0];
        int maxGlobal = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            maxCurr = max(nums[i], maxCurr + nums[i]);
            
            if (maxCurr > maxGlobal) {
                maxGlobal = maxCurr;
            }
        }
        return maxGlobal;
    }
};