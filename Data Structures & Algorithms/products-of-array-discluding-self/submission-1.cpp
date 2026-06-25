class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       vector<int>pre;
       vector<int>post;
       int n=nums.size();
       int mul1=1;
       int mul2=1;
       vector<int>ans(n,-1);

       for(int i=0;i<n;i++)
       {
        mul1*=nums[i];
        pre.emplace_back(mul1);
        mul2*=nums[n-i-1];
        post.emplace_back(mul2);
       }
        reverse(post.begin(),post.end());
       for(int i=0;i<n;i++)
       {
        if(i==0) ans[i]=post[i+1];
        else if(i==n-1) ans[i]=pre[i-1];
        else{
            ans[i]=pre[i-1]*post[i+1];
        }
       }
    return ans;
    }
};








