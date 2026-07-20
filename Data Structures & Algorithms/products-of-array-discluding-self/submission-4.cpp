class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZero = 0, pdt = 1;
        for(auto it : nums){
            if(it == 0){
                countZero++;
            }
            else{
                pdt *= it;
            }
        }
        if(countZero > 1) return vector<int> (nums.size(), 0);
        vector<int> ans(nums.size(), 0);
        for(auto i = 0 ;i < nums.size() ; i++){
            if(countZero > 0){
                ans[i] = nums[i] == 0 ? pdt : 0;
            }
            else{
                ans[i] = pdt / nums[i];
            }
        }
        return ans;
    }
};
