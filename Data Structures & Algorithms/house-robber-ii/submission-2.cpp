class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int ind, int start, int end){
        if(ind < start) return 0;
        if(ind == start) return nums[ind];
        if(dp[ind] != -1) return dp[ind];
        
        int pick = nums[ind] + solve(nums, dp, ind-2, start, end);
        int notPick = solve(nums, dp, ind-1, start, end);

        return dp[ind] = max(pick, notPick);


    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        return max(solve(nums, dp1, n-2, 0, n-2), solve(nums, dp2, n-1, 1, n-1));
    }
};
