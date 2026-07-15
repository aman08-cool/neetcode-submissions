class Solution {
public:
    int solve(int ind, vector<int>& cost, vector<int>& dp){
        if(ind < 0 ) return 0;
        if(ind == 0 || ind == 1) return cost[ind];
        if(dp[ind] != -1) return dp[ind];
        
        int pick = solve(ind-2, cost, dp) + cost[ind];
        int notPick = solve(ind-1, cost, dp) + cost[ind];

        return dp[ind] = min(pick, notPick);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return min(solve(n-1, cost, dp), solve(n-2, cost, dp));
    }
};
