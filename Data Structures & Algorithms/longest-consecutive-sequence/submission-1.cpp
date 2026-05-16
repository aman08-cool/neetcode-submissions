class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size() == 0) return 0;
        int len = 1, maxLen = 1;
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] == nums[i - 1]) {
                continue;
            }
            else if(nums[i] == nums[i - 1] + 1) {
                len++;
            }
            else {
                len = 1;
            }
            maxLen = max(maxLen,len);
        }
        return maxLen;
    }
};
