// Question : https://leetcode.com/problems/generate-parentheses/description/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {};
        }
        vector<string> solutions;
        string temp;
        backtrack(solutions, temp, n, 0, 0);
        return solutions;
    }
    
    void backtrack(vector<string>& solutions, string temp, int n, int open, int close) {
        if (temp.size() == n*2 && open == close) {
            solutions.push_back(temp);
            return;
        } 
        

        if (open < n) {
            backtrack(solutions, temp + "(", n, open + 1, close);
        }
        if (close < n && close < open) {
            backtrack(solutions, temp + ")", n, open, close + 1);
        }
    }
};