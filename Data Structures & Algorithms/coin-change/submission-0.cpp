class Solution {
   public:
    int solve(int i, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (i == 0) {
            if (target % coins[i] == 0) {
                return target / coins[i];
            } else {
                return 1e9;
            }
        }
        if (dp[i][target] != -1) return dp[i][target];

        int notTake = solve(i - 1, target, coins, dp);
        int take = (coins[i] > target) ? 1e9 : 1 + solve(i, target - coins[i], coins, dp);

        return dp[i][target] = min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans =  solve(n-1, amount, coins, dp);
        if(ans >= 1e9){
             return -1;
        }
        return ans;
    }
};
