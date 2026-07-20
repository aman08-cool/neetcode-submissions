class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int ans = 0;
        for(auto it : st){
            if(!st.count(it-1)){
                int streak = 0;
                int curr = it;
                while(st.count(curr)){
                    streak++;
                    curr++;
                }
                ans = max(ans, streak);
            }
        }
        return ans;

    }
};
