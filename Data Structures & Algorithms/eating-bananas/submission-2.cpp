class Solution {
public:
    long long countH(vector<int>& piles, int k){
        long long cH = 0;
        for(auto& it : piles){
            cH += ceil(double(it) / k);
        }
        return cH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low <= high){
            double mid = low + (high-low)/2;
            if(countH(piles, mid) <= h){
                high = mid -1;
                ans = mid;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
