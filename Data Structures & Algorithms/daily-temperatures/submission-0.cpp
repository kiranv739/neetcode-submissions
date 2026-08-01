class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> s;
        int n = t.size();
        vector<int>ans(n,0);

        for(int i=n-1;i>=0;i--){
           if(s.empty()){
            s.push(i);
            ans[i] = 0; 
           }
           else{
            while(!s.empty() && t[i]>=t[s.top()]) s.pop();
            if(s.empty()){
                ans[i] = 0;
            }
            else{
                ans[i]= s.top()-i;
            }
            s.push(i);
           }
        }
    return ans;
    }
};
