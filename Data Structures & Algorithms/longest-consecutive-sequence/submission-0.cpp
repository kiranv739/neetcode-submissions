class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_set<int>s;
     int longest=0;
     for(int i=0;i<nums.size();i++)
     {
        s.insert(nums[i]);
     }   

     for(auto it : s)
     {
        if(s.find(it-1)==s.end())
        {
            int x = it;
            int cnt=0;
            while(s.find(x)!=s.end())
            {
                cnt++;
                x++;
            }
        longest = max(cnt,longest);
        }
     }
    return longest;
    }
};
