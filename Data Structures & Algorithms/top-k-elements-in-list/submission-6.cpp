class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        using pii = pair<int,int>;
        unordered_map<int,int> mp;
        for(auto& it : nums){
            mp[it]++;
        }
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        for(auto& it : mp){
            pq.push({it.second, it.first});
            if(pq.size() > k ){
                pq.pop();
            }
        }
        vector<int> ans;
        while(k--){
            ans.push_back({pq.top().second});
            pq.pop();
        }
        return ans;
    }
};
