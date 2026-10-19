class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, 
    int k) {
        int steps = 0;
        vector<int> res(n,INT_MAX);
        queue<pair<int,int>> q; // distance,node
        unordered_map<int,vector<pair<int,int>>> adj;

        for(auto f : flights){
            adj[f[0]].push_back({f[1],f[2]});
        }
        
        q.push({0,src});
        res[src] = 0;

        while(!q.empty() && steps<=k){
            int sz = q.size();
            while (sz--) {
                auto [dis, node] = q.front();
                q.pop();

                for (auto a : adj[node]) {
                    int next = a.first;
                    int price = a.second;

                    if (dis + price < res[next]) {
                        res[next] = dis + price;
                        q.push({res[next], next});
                    }
                }
            }
        steps++;
        }
    return res[dst] == INT_MAX ? -1 : res[dst];
    }
};
