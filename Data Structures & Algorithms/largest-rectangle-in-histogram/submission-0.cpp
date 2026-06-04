class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;
        for(int i = 0; i < n ; i++){
            int left = i;
            int right = i;
            while(left >= 0 && heights[left] >= heights[i]){
                left--;
            }
            while(right < n && heights[right] >= heights[i]){
                right++;
            }
            int width = right-left-1;
            maxArea = max(maxArea, heights[i]*width);
        }
        return maxArea;
    }
};
