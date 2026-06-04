class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        while( s <= e){
            int mid = (s+e)/2;
            if( nums[mid] > target){
                e--;
            }else if(nums[mid] < target){
                s++;
            }else{
                return mid;
            }
        }
        return -1;
    }
};
