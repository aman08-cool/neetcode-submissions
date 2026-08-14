class KthLargest {
public:
    vector<int> ans;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->ans = nums;this->k = k;
    }
    
    int add(int val) {
        ans.push_back(val);
        sort(ans.begin(), ans.end());
        return ans[ans.size()-k];
        
    }
};
