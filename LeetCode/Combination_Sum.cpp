// Question : https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        set<vector<int>> solutions;
        vector<int> temp;
        backtrack(candidates, solutions, temp, target, 0);
        return vector<vector<int>>(solutions.begin(), solutions.end());
    }
    
    void backtrack(vector<int>& candidates, set<vector<int>>& solutions, vector<int>& temp, int remaining, int start) {
        if (remaining == 0) {
            solutions.insert(temp);
            return;
        } 
        if (remaining < 0) {
            return;
        }
        
        for (int i = start; i < candidates.size(); i++) {
            temp.push_back(candidates[i]);
            backtrack(candidates, solutions, temp, remaining - candidates[i], i);
            temp.pop_back();
        }
    }
};