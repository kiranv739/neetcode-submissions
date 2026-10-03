class Solution {
public:
    bool dfs(int i, 
    vector<int>& ans,
    unordered_map<int,vector<int>>& pre,
    unordered_map<int,bool>& visited,
    unordered_map<int,bool>& finished)
    {
        if(visited[i]==true) return false;
        if(finished[i]==true) return true;
        if(pre[i].empty()){
            ans.push_back(i);
            finished[i]=true;
            return true;
        }

        visited[i]=true;

        for(auto x : pre[i]){
            if(dfs(x,ans,pre,visited,finished)==false) return false;
        }

        pre[i].clear();
        visited[i]=false;
        finished[i]=true;
        ans.push_back(i);

        return true;
    }
    
    
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        unordered_map<int,vector<int>> pre;
        unordered_map<int,bool> visited;
        unordered_map<int,bool> finished;
        
        for(int i=0;i<n;i++){
            visited[i] = false;
            finished[i] = false;
        }
        
        for(auto p : prerequisites){
            pre[p[0]].push_back(p[1]);
        }

        for(int i=0;i<n;i++){  
            if(dfs(i,ans,pre,visited,finished)==false) return {};
        }
    return ans;
    }
};
