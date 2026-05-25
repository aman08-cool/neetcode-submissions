class Solution {
   public:
    int count = 0;
    void isPal(string& s, int l, int r) {
        int n = s.length();
        while (l >= 0 && r < n && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
    }
    int countSubstrings(string s) {
        for (int i = 0; i < s.length(); i++) {
            isPal(s, i, i);
            isPal(s, i, i + 1);
        }
        return count;
    }
};
