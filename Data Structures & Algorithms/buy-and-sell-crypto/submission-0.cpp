class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        int maxi = price[n-1];
        int diff = 0;
        for(int i=n-1;i>=0;i--){
            diff = max(diff,maxi-price[i]);
            maxi = max(maxi,price[i]);
        }
        return diff;
    }
};
