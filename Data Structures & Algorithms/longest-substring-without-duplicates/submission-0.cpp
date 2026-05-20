class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_set<char> charSet;
        int l = 0;
        int maxStrlen = 0;
        for(int r = 0; r < n ; r++){
            while(charSet.count(s[r])){
                charSet.erase(s[l]);
                l++;
            }
            charSet.insert(s[r]);
            maxStrlen = max(maxStrlen, r-l+1);
        }
        return maxStrlen;
    }
};
