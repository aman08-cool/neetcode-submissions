class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxStreak = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        for(auto& it : st){
            if(!st.count(it-1)){
                int streak = 0;
                int curr = it;
                while(st.count(curr)){
                    streak++;
                    curr++;
                }
                maxStreak = max(maxStreak, streak);
            }
        }
        return maxStreak;

    }
};
