// Question : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/
class Solution {
private:
    int m;
    int n;
public:
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> visited(n, vector<int> (m, 0));
        int longestPath = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                longestPath = max(longestPath, backtrack(matrix, i, j, visited));
            }
        }
        
        return longestPath;
    }
    
    int backtrack(vector<vector<int>>& matrix, int x, int y, vector<vector<int>>& visited) {
        if (x < 0 || x >= n || y < 0 || y >= m) {
			return 0;
        }
        
        if (visited[x][y] != 0) {
            return visited[x][y];
        }
        
        int longestPath = 0;
        if (x + 1 < n && matrix[x + 1][y] > matrix[x][y]) {
            longestPath = max(longestPath, backtrack(matrix, x + 1, y, visited));
        }
		if (x - 1 >= 0 && matrix[x - 1][y] > matrix[x][y]) {
			longestPath = max(longestPath, backtrack(matrix, x - 1, y, visited));
        }
		if (y + 1 < m && matrix[x][y + 1] > matrix[x][y]) {
			longestPath = max(longestPath, backtrack(matrix, x, y + 1, visited));
        }
		if (y - 1 >= 0 && matrix[x][y - 1] > matrix[x][y]) {
			longestPath = max(longestPath, backtrack(matrix, x, y - 1, visited));
        }
        visited[x][y] = longestPath + 1;
        return visited[x][y];
    }
};