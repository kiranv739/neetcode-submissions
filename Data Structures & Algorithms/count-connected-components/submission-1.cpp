class Solution {
public:
    void dfs(int i,
    vector<bool>& visited,
    unordered_map<int,vector<int>>& adj)
    {
        visited[i]=true;
        for(auto x:adj[i]){
            if(visited[x]==false){
                dfs(x,visited,adj);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n,false);
        unordered_map<int,vector<int>> adj;
        int cnt = 0;

        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(i,visited,adj);
                cnt++;
            }
        }
    return cnt;
    }
};
