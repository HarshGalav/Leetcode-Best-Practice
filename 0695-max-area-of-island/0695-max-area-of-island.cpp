class Solution {
public:
     void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid,int &count) {
        int n = grid.size();
        int m = grid[0].size();
        vis[i][j] = 1;
        count++;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        for(int k = 0; k < 4; k++){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(ni >= 0 && nj >= 0 && ni < n && nj < m 
               && grid[ni][nj] == 1 && vis[ni][nj] == -1){
                dfs(ni, nj, vis, grid,count);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, -1));
        int count = 0;
        int area=0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == -1){
                    count=0;
                    dfs(i, j, vis, grid,count);
                    area=max(area,count);
                }
            }
        }
        return area;
    }
};
