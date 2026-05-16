class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 1;
        for (auto it : nums) {
            if (!st.count(it - 1)) {
                int len = 1;
                int ele = it;
                while (st.count(ele + 1)) {
                    ele++;
                    len++;
                }
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};
