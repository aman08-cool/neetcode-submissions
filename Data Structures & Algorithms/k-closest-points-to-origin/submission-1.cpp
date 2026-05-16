class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        using pii = pair<int, vector<int>>;
        priority_queue<pii, vector<pii>> pq;
        for (auto& it : points) {
            int dist = it[0] * it[0] + it[1] * it[1];
            pq.push({dist, {it[0], it[1]}});
            if(pq.size() > k) pq.pop();
        }
        vector<vector<int>> res;
        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
