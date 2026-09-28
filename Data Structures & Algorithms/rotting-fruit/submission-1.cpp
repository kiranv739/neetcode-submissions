class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int time = 0;
        queue<pair<pair<int,int>,int>>q;
        int fresh = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        
        vector<pair<int,int>> neighbors = {{-1,0},{0,-1},{0,1},{1,0}};
        while(!q.empty() && fresh>0){
                auto [r,c] = q.front().first;
                int t = q.front().second;
                q.pop();
                for(auto nei : neighbors){
                int r2 = r + nei.first;
                int c2 = c + nei.second;

                if(r2<0 || c2<0 || r2>=n || c2>=m)
                    continue;
                if(grid[r2][c2]!=1)
                    continue;
                grid[r2][c2]=2;
                fresh--;
                time = max(time,t+1);
                q.push({{r2,c2},t+1});
            }
            
        }
    return fresh==0 ? time : -1;
    }
};
