class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        int s = 0, e = n-1, lmax = 0, rmax = 0, ans = 0;
        while(s < e){
            lmax = max(lmax, heights[s]);
            rmax = max(rmax, heights[e]);

            if(heights[s] < heights[e]){
                ans += lmax-heights[s];
                s++;
            }else{
                ans += rmax-heights[e];
                e--;
            }
        }
        return ans;
    }
};
