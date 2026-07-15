class Solution {
public:
    int houseRobbbers(vector<int>& nums, int start, int end){
        if(nums.size() == 1) return nums[0];
        int prev = nums[start];
        int prev2 = 0;
        for(int i = start+1 ; i <= end ; i++){
            int pick = nums[i];
            if(i > 1){
                pick += prev2;
            }
            int notPick = prev;
            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(houseRobbbers(nums, 0 , n-2), houseRobbbers(nums, 1, n-1));
    }
};