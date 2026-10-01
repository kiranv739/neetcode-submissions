class Solution {
public:
    vector<pair<int,int>> directions = {{1,0},{0,-1},{0,1},{-1,0}};

    void dfs(int r,int c,vector<vector<bool>>& matrix,vector<vector<bool>>& visited,vector<vector<int>>& heights){
        visited[r][c] = true;
        for(auto dir : directions){
            int r2 = r + dir.first;
            int c2 = c + dir.second;
            
            if(r2<0 || r2>=heights.size() || c2<0 || c2>=heights[0].size())
                continue;
            if(visited[r2][c2])
                continue;
            
            if(heights[r2][c2]>=heights[r][c]){
                matrix[r2][c2] = true;
                dfs(r2,c2,matrix,visited,heights);
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> pas(n,vector<bool>(m,false));
        vector<vector<bool>> atla(n,vector<bool>(m,false));
        vector<vector<bool>> visitedP(n,vector<bool>(m,false));
        vector<vector<bool>> visitedA(n,vector<bool>(m,false));
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0){
                    pas[i][j] = true;
                }
                if(i==n-1 || j==m-1){
                    atla[i][j] = true;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pas[i][j] && !visitedP[i][j]){
                    dfs(i,j,pas,visitedP,heights);
                }
                if(atla[i][j] && !visitedA[i][j]){
                    dfs(i,j,atla,visitedA,heights);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pas[i][j] && atla[i][j]){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    ans.push_back(temp);
                }
            }
        }
    return ans;
    }
};
