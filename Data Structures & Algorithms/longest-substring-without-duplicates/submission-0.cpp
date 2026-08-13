class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int l = 0;
        int maxlen = 0;

        for (int r = 0; r < s.size(); r++) {
            if (m.find(s[r]) != m.end()) {
                l = max(l, m[s[r]] + 1);
            }

            m[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
        }

        return maxlen;
    }
};
