class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0;
       int right = nums.size()-1;
       int sum=INT_MIN;
       while(left<right)
       {
         sum=nums[left]+nums[right];

         if(sum==target) return {left+1,right+1};
         else if(sum>target) right--;
         else if(sum<target) left++;
       } 
    return {};
    }
};
