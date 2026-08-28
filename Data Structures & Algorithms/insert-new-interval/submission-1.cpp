class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> ans;
        //left side
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        //intersecting intervals, has the current started before new ended
        while(i < n && intervals[i][0] <= newInterval[1]){
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        //created the new range, now push it.
        ans.push_back(newInterval);
        //other leftout on right side.
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
