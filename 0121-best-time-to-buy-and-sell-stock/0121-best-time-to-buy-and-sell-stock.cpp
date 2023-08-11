class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_max = 0, max_profit=0;
        vector<int> t(prices.size());
        
        for(int i=prices.size()-1;i>=0;i--){
            curr_max = max(curr_max,prices[i]);
            t[i] = curr_max;
        }
        
        for(int i=0;i<prices.size();i++) max_profit = max(max_profit,t[i]-prices[i]);
            
        return max_profit;
    }
};