class Solution {
public:
    int profits(vector<int>& prices, int index, int buy, vector<vector<int>>& dp,int fee) {
        if (index >= prices.size()) return 0;
        if (dp[index][buy] != -1) return dp[index][buy];
        int profit;
        if (buy) {
            profit = max(-prices[index]+ profits(prices, index + 1, 0, dp,fee), profits(prices, index + 1, 1, dp,fee));
        } else {
            profit = max(prices[index] -fee+ profits(prices, index + 1, 1, dp,fee),profits(prices, index + 1, 0, dp,fee));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return profits(prices,0,1,dp,fee);
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                if (buy == 1) {
                    dp[index][buy] = max(-prices[index] + dp[index + 1][0],dp[index + 1][1]);
                } else dp[index][buy] = max(prices[index] -fee+ dp[index + 1][1], dp[index + 1][0]);
            }
        }
        return dp[0][1];
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n == 0) return 0;
        int next_buy = 0;  
        int next_sell = 0; 
        for (int index = n - 1; index >= 0; index--) {
            int curr_buy = max(-prices[index] + next_sell, next_buy);
            int curr_sell = max(prices[index] - fee + next_buy, next_sell);
            next_buy = curr_buy;
            next_sell = curr_sell;
        }
        return next_buy;
    }
};