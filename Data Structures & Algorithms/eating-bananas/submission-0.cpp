class Solution {
   public:
    long long countHourly(vector<int>& piles, int k) {
        long long countH = 0;
        for (auto& it : piles) {
            countH += ceil((double)it / (double)k);
        }
        return countH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1, high = *max_element(piles.begin(), piles.end());
        while (low <= high) {
            int mid = (low + high) / 2;
            if (countHourly(piles, mid) <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
