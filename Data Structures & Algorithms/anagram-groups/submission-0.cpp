class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        set<string>s;
        map<string,vector<string>>mp;
        for(auto it : strs)
        {
            sort(it.begin(),it.end());
            s.insert(it);
        }
       
        for(auto it : strs)
        {
            auto x=it;
            sort(x.begin(),x.end());
            mp[x].emplace_back(it);
        }
        for(auto it : s)
        {
           ans.emplace_back(mp[it]);
        }
    return ans;
    }
};
