// Question : https://leetcode.com/problems/permutations/description/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> solutions;
        vector<int> temp;
        backtrack(solutions, temp, nums);
        return solutions;
    }
    
    void backtrack(vector<vector<int>>& solutions, vector<int>& temp, vector<int>& nums) {
        if (temp.size() == nums.size()) {
            solutions.push_back(temp);
            return;
        } else {
            for (int i = 0; i < nums.size(); ++i) {
                if (find(temp.begin(), temp.end(), nums[i]) != temp.end()) continue;
                temp.push_back(nums[i]);
                backtrack(solutions, temp, nums);
                temp.pop_back();
            }
        }
    }
};