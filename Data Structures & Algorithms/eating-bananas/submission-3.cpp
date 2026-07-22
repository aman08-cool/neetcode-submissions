class Solution {
   public:
    long long countH(int rate, vector<int>& piles, int h){
        long long cH = 0;
        for(int i = 0 ; i < piles.size(); i++){
            cH += ceil((double)piles[i] / rate);
        }
        return cH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), ans = high;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if(countH(mid, piles, h) <= h){
                ans = mid;
                high = mid-1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};
