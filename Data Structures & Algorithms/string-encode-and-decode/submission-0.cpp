#include<bits/stdc++.h>
class Solution {
public:

    string encode(vector<string>& strs) {
       string enc = "";

       for(auto it : strs)
       {
          enc += to_string(it.size())+'#'+it;
       }
       return enc;
    }

    vector<string> decode(string s) {
      vector<string>ans;

      int i=0;
      while(i<s.size())
      {
        int j=i;
        while(s[j]!='#') j++;
        int length = stoi(s.substr(i,j-i));
        ans.emplace_back(s.substr(j+1,length));
        i = j+1+length;
      }
    return ans;
    }
};
