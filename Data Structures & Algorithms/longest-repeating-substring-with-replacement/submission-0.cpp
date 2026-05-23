class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(), l = 0, maxF = 0, maxLen = 0;
        
        unordered_map<int,int> count;

        for(int r = 0; r < n ; r++){
            count[s[r]]++;

            maxF = max(maxF, count[s[r]]);

            while((r-l+1)-maxF > k){
                count[s[l]]--;
                l++;
            }
            
            maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};
