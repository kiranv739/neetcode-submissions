class Solution {
public:
    bool isAnagram(string s, string t) {
    unordered_map<char,int>ms;
    unordered_map<char,int>mt;
    
    for(int i=0;i<s.size();i++){
        ms[s[i]]++;
    }
    for(int i=0;i<t.size();i++){
        mt[t[i]]++;
    }

    return ms == mt;
    }
};
