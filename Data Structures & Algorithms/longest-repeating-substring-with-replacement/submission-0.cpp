class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> m;
        int l=0;
        int r=0;
        int maxlen=0;
        int maxf=0;

        while(r<s.size()){
            m[s[r]]++;
            maxf = max(maxf,m[s[r]]);
            while(((r-l+1)-maxf) > k){
                m[s[l]]--;
                if(m[s[l]]==0) m.erase(s[l]);
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
    return maxlen;
    }
};
