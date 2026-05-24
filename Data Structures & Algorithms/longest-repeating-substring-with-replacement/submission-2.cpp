class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int> count;
        int l = 0,maxf = 0, maxLen = 0;
        for(int r = 0; r < s.size() ; r++){
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);
            while((r-l+1)-maxf > k){
                count[s[l]]--;
                l++;
            }
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
