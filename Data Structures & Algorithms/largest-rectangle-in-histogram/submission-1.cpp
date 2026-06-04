class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n);
        vector<int> right(n);
        stack<int> st;

        //Next smaller left
        for(int l = 0 ; l < n ;l++){
            while(!st.empty() && heights[st.top()] >= heights[l]){
                st.pop();
            }
            left[l] = st.empty() ? -1 : st.top();
            st.push(l);
        }
        while(!st.empty()) st.pop();
        //Next smaller right
        for(int r = n-1; r >= 0; r--){
            while(!st.empty() && heights[st.top()] >= heights[r]){
                st.pop();
            }
            right[r] = st.empty() ? n : st.top();
            st.push(r);
        }
        int maxArea = 0;
        for(int i = 0 ; i < n ;i++){
            int width = (right[i]-left[i]-1);
            maxArea = max(maxArea, heights[i]*width);
        }
        return maxArea;
    }
};
