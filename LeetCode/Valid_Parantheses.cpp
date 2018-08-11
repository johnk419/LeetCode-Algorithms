// Question : https://leetcode.com/problems/valid-parentheses/description/

class Solution {
public:
    bool isValid(string s) {
        string temp = "";

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                temp.push_back(s[i]);
            } else if (s[i] - 2 == temp.back() || s[i] - 1 == temp.back()) {
                temp.pop_back();
            } else {
                return false;
            }
        }
        return temp.size() == 0;

    }
};