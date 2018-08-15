// Question : https://leetcode.com/problems/combinations/description/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> solutions;
        vector<int> temp;
        if (k == 0 || n == 0) {
            return {{}};
        }
        backtrack(solutions, temp, n, k);
        return solutions;
    }
    
    void backtrack(vector<vector<int>>& solutions, vector<int>& temp, int n, int k) {
        if (temp.size() == k) {
            solutions.push_back(temp);
            return;
        }
              
        for (int i = (temp.size() > 0 ? temp[temp.size() - 1] + 1 : 1); i <=n; ++i) {
            temp.push_back(i);
            backtrack(solutions, temp, n, k);
            temp.pop_back();
        }
    }
};