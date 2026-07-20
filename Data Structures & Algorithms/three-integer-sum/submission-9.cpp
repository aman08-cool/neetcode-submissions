class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        //fix the one pointer "first = nums[i]"
        for(int i = 0 ; i < n ; i++){
            if(nums[i] > 0){
                break; // all remaining are positive.
            }
            //Skip duplicates for First number
            if(i > 0 && nums[i] == nums[i-1]) continue;

            //Traverse using Second & Third pointer
            int l = i + 1, r = n-1;
            while( l < r){
                int threesum = nums[i] + nums[l] + nums[r];
                if(threesum > 0){
                    r--;
                }else if( threesum < 0){
                    l++;
                }
                else{
                     ans.push_back({nums[i], nums[l], nums[r]});
                     l++;
                     r--;
                     //skips duplicates for left
                     while( l < r && nums[l] == nums[l-1]){
                        l++;
                     }   
                }
            }
        }
        return ans;
    }
};
