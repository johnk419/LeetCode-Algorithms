// Question : https://leetcode.com/problems/combination-sum/description/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> solution;
        vector<int> temp;
        backtrack(solution, candidates, temp, target, 0);
        return solution;
    }
    
    void backtrack(vector<vector<int>>& solution, vector<int>& candidates, vector<int>& temp, int remain, int start) {
        if (remain == 0) {
            solution.push_back(temp);
            return;
        } else if (remain < 0) {
            return;
        }
        temp.push_back(candidates[start]);
        backtrack(solution, candidates, temp, remain - candidates[start], start);
        temp.pop_back();
        if (start+1 < candidates.size()) {
            backtrack(solution, candidates, temp, remain, start + 1);
        }
    }
};