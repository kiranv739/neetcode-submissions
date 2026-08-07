class Solution
{
public:
    vector<int> NSE(vector<int>arr){
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=n;
            }
            else{
               ans[i] = s.top();
            }
            s.push(i);
        }

        return ans;
    }

    vector<int> PSE(vector<int>arr){
        int n = arr.size();
        stack<int> s;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            if(s.empty()){
                ans[i]=-1;
            }
            else{
               ans[i] = s.top();
            }
            s.push(i);
        }

        return ans;
    }
    int largestRectangleArea(vector<int> &heights) {
        vector<int> nse = NSE(heights);
        vector<int> pse = PSE(heights);
        int maxi = 0;
        int n = heights.size();

        for(int i=0;i<n;i++){
            int right = nse[i] - 1;
            int left = pse[i] + 1;
            int area = heights[i]*(right - left + 1);
            maxi = max(maxi,area);
        }
    return maxi;
    }
};