class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int ref = INT_MAX;
        vector<int> :: iterator it;
        for(it = prices.begin();it<prices.end();it++){
            if(ref > *it)
                ref = *it;
            int temp = *it - ref;
            max_profit = max(temp,max_profit);
        }
        return max_profit;
    }
};