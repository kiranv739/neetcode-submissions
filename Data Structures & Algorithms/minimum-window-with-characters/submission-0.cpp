class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>m;
        for(auto x:t){
            m[x]++;
        }
        int r=0;
        int l=0;
        int mini=INT_MAX;
        int cnt=0;
        int sindex=-1;

        while(r<s.size()){
            if(m.find(s[r])==m.end()) m[s[r]]=0;
            if(m[s[r]]>0) cnt++;
            m[s[r]]--;

            while(cnt==t.size()){
                if(r-l+1 < mini){
                    mini = r-l+1;
                    sindex=l;
                }
                m[s[l]]++;
                if(m[s[l]]>0) cnt--; 
                l++;
            }
            r++;
        }
    return sindex == -1 ? "" : s.substr(sindex,mini);
    }
};
