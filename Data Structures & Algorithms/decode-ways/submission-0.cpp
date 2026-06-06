class Solution {
   public:
    int solve(string& s, int ind, int n, vector<int>& dp) {
        if (ind == n) return 1;
        if (s[ind] == '0') return 0;
        if(dp[ind] != -1) return dp[ind];

        int take1 = solve(s, ind + 1, n, dp);
        int take2 = 0;
        if (ind + 1 < n) {
            int digit = (s[ind] - '0') * 10 + (s[ind + 1] - '0');
            if (digit >= 10 && digit <= 26) {
                take2 = solve(s, ind + 2, n, dp);
            }
        }
        return dp[ind] = take1 + take2;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, -1);

        return solve(s, 0, n , dp);
    }
};
