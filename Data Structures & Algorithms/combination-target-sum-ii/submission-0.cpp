class Solution {
   public:
    void solve(int ind, int target, vector<int>& candidates, vector<vector<int>>& CombSum2,
               vector<int>& temp) {
        int n = candidates.size();
        if (target == 0) {
            CombSum2.push_back(temp);
            return;
        }
        for (int i = ind; i < n; i++) {
            if (i > ind && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;

            temp.push_back(candidates[i]);
            solve(i + 1, target - candidates[i], candidates, CombSum2, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> CombSum2;
        solve(0, target, candidates, CombSum2, temp);
        return CombSum2;
    }
};
