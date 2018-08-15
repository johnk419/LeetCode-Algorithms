// Question : https://leetcode.com/problems/string-to-integer-atoi/description/

class Solution {
public:
    int myAtoi(string str) {
        int res = 0;
        int start = 0;
        int sign = 1;  
        
        for (int i = 0; i < str.size(); ++i) {
            if (str[i] - '0' == -16) {
                start++;
            } else {
                break;
            }
        }
        
        int curChar = str[start] - '0';
        //-3 is '-'
        if (curChar == -3) {
            sign = -1;
            start++;
        //-5 is '+'
        } else if (curChar == -5) {
            start++;
        } else if (curChar < 0 || curChar > 9) {
            return 0;
        }
        
        int previousRes = 0;
        for (int i = start; i < str.size(); ++i) {
            int curChar = str[i] - '0';
            if (curChar <= 9 && curChar >= 0) {
                previousRes = res;
                res = res * 10 + curChar;
                if (res < 0 || (res - curChar) / 10 != previousRes) {
                    return sign == 1 ? INT_MAX : INT_MIN;
                }
            } else {
                break;
            }
        }
        cout << res << endl;
        return res * sign;
    }
};