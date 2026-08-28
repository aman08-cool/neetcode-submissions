class Solution {
   public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReached = 0;
        for (int i = 0; i < n; i++) {
            if (i > maxReached) return false;
            maxReached = max(i + nums[i], maxReached);
            if (maxReached >= n) return true;
        }
        return true;
    }
};
