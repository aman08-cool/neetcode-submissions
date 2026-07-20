class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res = 0;
        for (auto it : st) {
            if (!st.count(it - 1)) {
                int streak = 0;
                int curr = it;
                while (st.count(curr)) {
                    streak++;
                    curr++;
                }
                res = max(res, streak);
            }
        }
        return res;
    }
};