// Question : https://leetcode.com/problems/jump-game/description/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int moves = 0;
        if (nums.size() == 1) {
            return true;
        }
        for (auto it = nums.begin() ; it < nums.end(); ++it) {
            if (moves <= *it) {
                moves = *it;
            } else {
                moves = moves - 1;
            }
            if (moves == 0 && it < nums.end() - 1) {
                return false;
            }
        }
        return true;
    }
};