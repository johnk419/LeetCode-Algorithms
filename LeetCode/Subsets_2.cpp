// Question : https://leetcode.com/problems/subsets-ii/description/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> solutions;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        backtrack(solutions, nums, temp, 0);
        return vector<vector<int>>(solutions.begin(), solutions.end());
    }
    
    void backtrack(set<vector<int>>& solutions, vector<int>& nums, vector<int>& temp, int index) {        
        if (temp.size() <= nums.size()) {
            solutions.insert(temp);
        } else {
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            if(i > index && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            backtrack(solutions, nums, temp, i + 1);
            temp.pop_back();
        }
        return;
    }
};