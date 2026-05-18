class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int minPrice = INT_MAX;
        for(int i = 0 ;i < prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            int profit = prices[i] - minPrice;
            maxProf = max(profit, maxProf);
        }
        return maxProf;
    }
};
