class Solution {
   public:
    void solve(int ind, vector<int>& nums, vector<vector<int>>& CombSum, vector<int>& temp,
               int target) {
        if (ind == nums.size()) {
            if (target == 0) {
                CombSum.push_back(temp);
            }
            return;
        }
        if (nums[ind] <= target) {
            temp.push_back(nums[ind]);
            solve(ind, nums, CombSum, temp, target - nums[ind]);
            temp.pop_back();
        }
        solve(ind + 1, nums, CombSum, temp, target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        vector<vector<int>> CombSum;
        solve(0, nums, CombSum, temp, target);
        return CombSum;
    }
};
