class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        for(int i = 0 ;i < nums.size() ; i++){
            int pdt = 1;
            for(int j = 0 ; j < nums.size() ; j++){
                if(i != j) pdt *= nums[j];
            }
            ans[i] = pdt;
        }
        return ans;
    }
};
