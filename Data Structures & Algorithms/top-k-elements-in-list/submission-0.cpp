class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        vector<vector<int>> ans(nums.size() + 1);
        vector<int> final;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }

        for(auto it : m)
        {
          ans[it.second].emplace_back(it.first);
        }
        
        for(int j = nums.size(); j >= 0 && k > 0; j--)
        {
            for(auto it : ans[j])
            {
                final.emplace_back(it);
                k--;
                if(k==0) break;
            }
        }
    return final;
    }
};
