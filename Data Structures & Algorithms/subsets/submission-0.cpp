class Solution {
public:
    void solve(vector<int>& nums,vector<int>& subsets,vector<vector<int>>& ans, int ind){
        if(ind >= nums.size()){
            ans.push_back(subsets);
            return;
        }

        subsets.push_back(nums[ind]);
        solve(nums, subsets, ans, ind+1);
        subsets.pop_back();
        solve(nums, subsets, ans, ind+1);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subsets;
        vector<vector<int>> ans;
        solve(nums, subsets, ans, 0);
        return ans;
    }
};
