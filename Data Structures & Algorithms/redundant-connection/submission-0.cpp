class Solution {
public:
    bool dfs(int start,int end,unordered_map<int,vector<int>>& adj,unordered_map<int,bool>& visited){
        visited[start] = true;
        if(start==end) return true;

        for(auto x:adj[start]){
            if(visited[x]) continue;
            if(dfs(x,end,adj,visited)==true) return true;
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        vector<int> ans;

        for(auto e:edges){
            unordered_map<int,bool> visited;

            if(dfs(e[0],e[1],adj,visited)==true){
                return {e[0],e[1]};
            }
                
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
    return {};
    }
};
