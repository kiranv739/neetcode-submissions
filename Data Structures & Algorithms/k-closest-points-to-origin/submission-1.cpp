class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> q;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];

            int dist = x*x + y*y;
            q.push({dist,points[i]});
            if(q.size()>k) q.pop();
        }
        vector<vector<int>> ans;
        while(!q.empty()){
            ans.push_back(q.top().second);
            q.pop();
        }
    return ans;
    }
};
