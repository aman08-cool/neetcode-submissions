class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s = 0, e = numbers.size()-1;
        while(s < e){
            int currSum = numbers[s] + numbers[e];
            if(currSum > target){
                e--;
            }
            else if(currSum < target){
                s++;
            }else{
                return {s+1, e+1};
            }
        }
        return {};
    }
};
