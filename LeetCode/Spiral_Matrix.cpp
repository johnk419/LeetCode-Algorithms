// Question : https://leetcode.com/problems/spiral-matrix/description/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int offset = 0; 
        int size = 0;
        vector<int> result;
        for (int i = 0; i < matrix.size(); ++i) {
            size = size + matrix[i].size();
        }
        if (size == 0) {
            return result;
        }
        
        int m = matrix[0].size();
        int n = matrix.size();
        int x = 0;
        while (x < size) {
            for (int i = offset; i < m - offset; ++i) {
                result.push_back(matrix[offset][i]);
                x++;
                if (result.size() == size) {
                    return result;
                }
            }
            for (int j = offset + 1; j < n - offset; ++j) {
                result.push_back(matrix[j][m - 1 - offset]);
                x++;
                if (result.size() == size) {
                    return result;
                }
            }
            for (int i = (m - 2) - offset; i > offset - 1; --i) {
                result.push_back(matrix[(n - 1)- offset][i]);
                x++;
                if (result.size() == size) {
                    return result;
                }
            }
            for (int j = (n - 2) - offset; j > 0 + offset; --j) {
                result.push_back(matrix[j][0 + offset]);
                x++;
                if (result.size() == size) {
                    return result;
                }
            }

            offset = offset + 1;   
        }
        return result;
    }
};