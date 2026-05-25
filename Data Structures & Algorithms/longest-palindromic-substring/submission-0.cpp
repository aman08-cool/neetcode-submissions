class Solution {
   public:
    int maxLen = 0, start;
    void isPal(string& s, int l, int r) {
        int n = s.length();
        while (l >= 0 && r < n && s[l] == s[r]) {
            if ((r - l + 1) > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    }
    string longestPalindrome(string s) {
        for (int i = 0; i < s.length(); i++) {
            isPal(s, i, i);
            isPal(s, i, i + 1);
        }
        return s.substr(start, maxLen);
    }
};
