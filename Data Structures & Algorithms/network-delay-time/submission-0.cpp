class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> res(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto t : times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        res[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto [dis,node] = pq.top();
            pq.pop();
            
            // if(dis > res[node]) continue;

            for(auto a : adj[node]){
                if(dis + a.second < res[a.first]){
                    res[a.first] = dis + a.second;
                    pq.push({dis+a.second,a.first});
                }
            }
        }
    int maxi=0;
    for(int i=1;i<=n;i++){
        maxi = max(maxi,res[i]);
    }
    
    return maxi == INT_MAX ? -1 : maxi;
    }
};
