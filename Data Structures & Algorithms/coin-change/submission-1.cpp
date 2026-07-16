class Solution {
public:
    int solve(vector<int>& coins, vector<vector<int>>& dp, int amount,
              int ind) {
        if (ind == 0) {
            return (amount % coins[ind] == 0) ? (amount / coins[ind]) : 1e9;
        }

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int notTake = solve(coins, dp, amount, ind - 1);
        int take = coins[ind] > amount
                       ? 1e9
                       : 1 + solve(coins, dp, amount - coins[ind], ind);

        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int ans = solve(coins, dp, amount, n - 1);
        return ans >= 1e9 ? -1 : ans;
    }
};