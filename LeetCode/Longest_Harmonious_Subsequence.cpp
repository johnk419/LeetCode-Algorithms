// Question : https://leetcode.com/problems/longest-harmonious-subsequence/description/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] = 1;
            } else {
                map[nums[i]] += 1;
            }
        }
        int max = 0;
        for (auto it : map) {
            auto f = map.find(it.first + 1);
            if (f != map.end()) {
                int res = it.second + f->second;
                if (max < res) {
                    max = res;
                }
            } 
        }
        
        return max;
    }
};