class Solution {
public:
    int inf = 2147483647;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [r,c] = q.front();
            q.pop();
            
            vector<pair<int,int>> nei = {{-1,0},{0,-1},{0,1},{1,0}};

            for(auto x : nei){
                int r2 = r+x.first;
                int c2 = c+x.second;

                if(r2<0 || c2<0 || r2>=n || c2>=m)
                    continue;
                if(grid[r2][c2]<=grid[r][c]+1) 
                    continue;
                grid[r2][c2]=grid[r][c]+1;
                q.push({r2,c2});
            }

        }
    }
};
