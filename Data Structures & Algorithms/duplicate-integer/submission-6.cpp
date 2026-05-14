class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> num;
        for(auto it : nums){
            if(num.count(it)){
                return true;
            }
            num.insert(it);
        }
        return false;
    }
};