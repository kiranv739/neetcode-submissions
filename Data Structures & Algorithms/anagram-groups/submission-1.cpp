class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        map<string,vector<string>>mp;
       
        for(auto it : strs)
        {
            auto x=it;
            sort(x.begin(),x.end());
            mp[x].emplace_back(it);
        }
        for(auto it : mp)
        {
           ans.emplace_back(it.second);
        }
    return ans;
    }
};
