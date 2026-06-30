class Solution {
public:
    int max_element(vector<int>& piles){
       int maxi=INT_MIN;
       for(int i=0;i<piles.size();i++)
       {
        maxi=max(maxi,piles[i]);
       }
       return maxi;
    }

    long long totalHours(int mid,vector<int>& piles){
        long long total=0;

        for(int i=0;i<piles.size();i++){
            total+=ceil( ( (double) piles[i]/ (double) mid) );
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int l=1,r=max_element(piles);

        while(l<=r)
        {
           int mid=(l+r)/2;
           if(totalHours(mid,piles)<=h) r=mid-1;
           else l=mid+1;
        }
    return l;
    }
};