class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
     int m=arr2.size();
     if(n>m) return findMedianSortedArrays(arr2,arr1);
     int l=0;
     int r=n;

     int med=(m+n+1)/2;

     while(l<=r){
        int mid1=(l+r)/2;
        int mid2= med-mid1;
        int l1=INT_MIN,l2=INT_MIN;
        int r1=INT_MAX,r2=INT_MAX;
        if(mid1<n) r1=arr1[mid1];
        if(mid2<m) r2=arr2[mid2];
        if(mid1-1>=0) l1=arr1[mid1-1];
        if(mid2-1>=0) l2=arr2[mid2-1];

        if(l1<=r2 && l2<=r1){
           if((n+m)%2==0) return ((double)(min(r1,r2)+max(l1,l2)))/2.0;
           else return (double)max(l1,l2);
        }
        if(l1>r2){
            r=mid1-1;
        }
        else if(l2>r1){
            l=mid1+1;
        }
        }
     return 0;
    }
};