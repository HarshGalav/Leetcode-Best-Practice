class Solution {
public:
    void dfs(int i,int j, vector<vector<int>>&pacific,vector<vector<int>>& heights){
        int n=pacific.size();
        int m=pacific[0].size();
        pacific[i][j]=1;
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,-1,1};
        for(int l=0;l<4;l++){
            int nx=i+dx[l];
            int ny=j+dy[l];
            if(nx>=0 && ny>=0 && nx<=n-1 && ny<=m-1 && pacific[nx][ny]!=1 && heights[nx][ny]>=heights[i][j]){
                dfs(nx,ny,pacific,heights);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));

        for(int j=0;j<m;j++){
            dfs(0,j,pacific,heights);
        }

        for(int j=0;j<n;j++){
            dfs(j,0,pacific,heights);
        }

        for(int j=0;j<m;j++){
            dfs(n-1,j,atlantic,heights);
        }

        for(int j=0;j<n;j++){
            dfs(j,m-1,atlantic,heights);
        }
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;

        
    }
};