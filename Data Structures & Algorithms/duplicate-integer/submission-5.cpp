class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        vector<int>nums1 = nums;
        sort(nums1.begin(), nums1.end());
        for(int i = 1 ; i < nums1.size() ; i++){
            if(nums1[i-1] == nums1[i]) return true;
        }
        return false;
    }
};