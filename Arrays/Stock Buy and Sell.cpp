class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int profit = 0;
        int min = INT_MAX;
        int n = prices.size();
        for(int i = 0;i<n;i++){
            if(min>prices[i]){
                min = prices[i];
            }
                profit = prices[i] - min;
            max_profit = max(profit,max_profit);
        }
        return max_profit;
    }
};
