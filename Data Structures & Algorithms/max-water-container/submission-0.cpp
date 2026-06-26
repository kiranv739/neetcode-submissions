class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxi=0;
        int n=heights.size();
        int l=0;
        int r=n-1;
        int product=0;

        while(l<r)
        {
            int h= min(heights[l],heights[r]);
            int w= r-l;
            product=h*w;
            maxi=max(maxi,product);

            if(heights[l]<heights[r]) l++;
            else r--;

        }
    return maxi;
    }
};
