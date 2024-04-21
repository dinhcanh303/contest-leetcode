class Solution {
public:
    int cnt[1000][10];
    int d[1000][10];
    int dfs(int i,int p, int n,int m){
        if(i == m) return 0;
        if(d[i][p]==0){
            for(int j = 0 ; j < 10; j++){
                if(i == 0 || j != p){
                    d[i][p] = max(d[i][p], cnt[i][j] + dfs(i+1, j , n ,m));
                }
            }
        }
        return d[i][p];
    }
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ++cnt[j][grid[i][j]];
            }
        }
        return n * m - dfs(0,0,n,m);
    }
};