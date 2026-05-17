class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pdt = 1, countZero = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0){
                countZero++;
            }
            else{
                pdt *= nums[i];
            }
        }
        if(countZero > 1){
            return vector<int>(nums.size(),0);
        }
        vector<int> res(nums.size(),0);
        for(int i = 0 ;i < nums.size() ; i++){
            if(countZero > 0){
                res[i] = (nums[i] == 0) ? pdt : 0;
            }else{
                res[i] = pdt / nums[i];
            }
        }
        return res;
    }
};
