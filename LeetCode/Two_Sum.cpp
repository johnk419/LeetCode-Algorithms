// Question : https://leetcode.com/problems/two-sum/description/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            int needToFind = target - nums[i];
            
            auto found = map.find(needToFind);
            if (found == map.end()) {
                map[nums[i]] = i;
            } else {
                result.push_back(found->second);
                result.push_back(i);
            }
        }
        return result;
    }
};