class Solution {
public:
    int trap(vector<int>& h) {
        int total=0,lmax=0,rmax=0;
        int n = h.size();
        int l=0;
        int r = n-1;

        while(l<r){
            if(h[l]<=h[r]){
                lmax = max(h[l],lmax);
                total += lmax - h[l];
                l++;
            }
            else{
                rmax = max(h[r],rmax);
                total += rmax - h[r];
                r--;
            }
        }
    return total;
    }
};
