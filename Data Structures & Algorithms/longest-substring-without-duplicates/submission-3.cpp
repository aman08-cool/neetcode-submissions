class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, maxLen = 0;
        unordered_set<int> st;
        for(int r = 0 ; r < s.length() ; r++){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
