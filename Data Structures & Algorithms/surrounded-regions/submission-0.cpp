class Solution {
public:
    vector<pair<int,int>> directions = {{1,0},{0,-1},{0,1},{-1,0}};

    void dfs(int r, int c, vector<vector<bool>>& o,
    vector<vector<bool>>& visited,vector<vector<char>>& board){
        visited[r][c] = true;
        for(auto dir : directions){
            int r2 = r + dir.first;
            int c2 = c + dir.second;
            
            if(r2<0 || r2>=board.size() || c2<0 || c2>=board[0].size())
                continue;
            if(visited[r2][c2])
                continue;
            
            if(board[r2][c2]=='O'){
                o[r2][c2]=true;
                dfs(r2,c2,o,visited,board);
            }
        }
        
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> o(n,vector<bool>(m,false));
        vector<vector<bool>> visited(n,vector<bool>(m,false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||i==n-1||j==0||j==m-1){
                    if(board[i][j]=='O'){
                        o[i][j] = true;
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(o[i][j] && !visited[i][j]){
                    dfs(i,j,o,visited,board);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            if(board[i][j]=='O' && o[i][j]==false)
                board[i][j]='X';
            }
        }        
    }
};
