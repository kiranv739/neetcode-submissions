class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int cost = 0;
        vector<bool> visited(points.size(),false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,0});

        while(!pq.empty()){
            auto [dis,node] = pq.top();
            pq.pop();
            if(visited[node]==true) continue;
            visited[node] = true;
            cost += dis;

            for(int i=0;i<points.size();i++){
                if(node!=i ){
                    int distance = abs(points[node][0]-points[i][0]) + 
                    abs(points[node][1]-points[i][1]);
                    pq.push({distance,i});
                }
            }
        }
    return cost;
    }
};
