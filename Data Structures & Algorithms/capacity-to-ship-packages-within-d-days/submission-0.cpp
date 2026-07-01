class Solution {
public:
    int noDays(vector<int>& weights,int mid){
        int days=1;
        int sum=0;
        
        for(int i=0;i<weights.size();i++){
            if(sum+weights[i] > mid){
                days++;
                sum=0;
            }
            sum+=weights[i];
        }
    return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
       int n=weights.size();
       int l= *max_element(weights.begin(),weights.end());
       int h= accumulate(weights.begin(),weights.end(),0) ;

       while(l<=h){
        int mid = (l+h)/2;
        int d = noDays(weights,mid);

        if(d<=days) h=mid-1;
        else l=mid+1;
       }
    return l;
    }
};