class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> maxValue(rows, vector<int>(cols, numeric_limits<int>::min()));
        maxValue[rows - 1][cols - 1] = grid[rows - 1][cols - 1];
        for(int i = rows - 1; i >= 0; --i) {
            for(int j = cols - 1; j >= 0; --j) {
                if(i < rows - 1){
                    maxValue[i][j] = max(maxValue[i][j], maxValue[i + 1][j]);
                }
                if(j < cols - 1){
                    maxValue[i][j] = max(maxValue[i][j], maxValue[i][j + 1]);
                }
                maxValue[i][j] = max(maxValue[i][j], grid[i][j]);
            }
        }
        int maxScore = numeric_limits<int>::min(); // Change min() to ::min()
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(i < rows - 1) {
                    maxScore = max(maxScore, maxValue[i + 1][j] - grid[i][j]);
                }
                if(j < cols - 1) {
                    maxScore = max(maxScore, maxValue[i][j + 1] - grid[i][j]);
                }
            }
        }
        return maxScore;
    }
};