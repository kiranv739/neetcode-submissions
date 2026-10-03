class Solution {
public:
    bool dfs(int i,int parent,int& cnt,
    vector<bool>& visited,
    unordered_map<int,vector<int>>& m)
    {
        visited[i]=true;
        cnt++;

        for(auto x:m[i]){
            if(visited[x]==false){
                if(dfs(x,i,cnt,visited,m)==false){
                    return false;
                }
            }
            else if(x!=parent) return false;
        }
    return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> m;
        vector<bool> visited(n,false);
        int cnt = 0;

        for(auto x:edges){
            m[x[0]].push_back(x[1]);
            m[x[1]].push_back(x[0]);
        }

        if(dfs(0,-1,cnt,visited,m)==false){
            return false;
        }
    
    return cnt==n;
    }
};
