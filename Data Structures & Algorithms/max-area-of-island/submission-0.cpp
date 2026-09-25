class Solution {
public:
    void dfs(int r,int c,int& cnt,vector<vector<int>>& grid,vector<vector<int>>& visited){
        if(r<0 || r>=grid.size() || c<0 || c>=grid[0].size() || visited[r][c]==1 || 
        grid[r][c]==0) return;

        visited[r][c] = 1;
        cnt++;

        dfs(r-1,c,cnt,grid,visited);
        dfs(r,c-1,cnt,grid,visited);
        dfs(r,c+1,cnt,grid,visited);
        dfs(r+1,c,cnt,grid,visited);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int cnt = 0;
                if(visited[i][j]==0 && grid[i][j]==1){
                    dfs(i,j,cnt,grid,visited);
                    ans = max(ans,cnt);
                }
            }
        }
    return ans;
    }
};
