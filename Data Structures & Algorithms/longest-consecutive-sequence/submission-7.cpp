class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(), nums.end());
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 1;
        for (auto& it : nums) {
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
