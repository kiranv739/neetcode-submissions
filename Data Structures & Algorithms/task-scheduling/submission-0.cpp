class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> m;
        for(auto x : tasks){
            m[x]++;
        }
        priority_queue<int> pq;
        queue<pair<int,int>> q;
        int time=0;

        for(auto x:m){
            pq.push(x.second);
        }

        while(!pq.empty() || !q.empty()){
            if(!q.empty() && time == q.front().second){
                pq.push(q.front().first);
                q.pop();
            }
            if(pq.empty()){
                time = q.front().second;
                continue;
            }
            int top = pq.top();
            pq.pop();
            time++;
            top--;
        
            if(top>0) q.push({top,time+n});
        }
    return time;
    }
};
