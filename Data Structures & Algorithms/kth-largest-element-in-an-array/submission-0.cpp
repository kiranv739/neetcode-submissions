class Solution {
public:
    int partition(vector<int>& nums, int l,int r){
       int i = l+1;
       int j = r;
       int pivot = nums[l];
       while(i<=j){
          if(nums[i]<pivot && nums[j]>pivot){
            swap(nums[i],nums[j]);
            i++;
            j--;
          }
          if(nums[i]>=pivot) i++;
          if(nums[j]<=pivot) j--;
       } 
       swap(nums[l],nums[j]);

       return j;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int l=0;
        int pivot_index = 0;
        int r=nums.size()-1;
        
        while(true){
           pivot_index = partition(nums,l,r);
           
           if(pivot_index == k-1) break;
           
           else if(pivot_index > k-1){
            r = pivot_index-1;
           }
           else{
            l = pivot_index+1;
           }
        }
        return nums[pivot_index];
    }
};
