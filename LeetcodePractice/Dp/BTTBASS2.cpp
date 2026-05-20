recursion and memoized;
class Solution {
public:
    int profits(vector<int>& prices,int index, int buy,vector<vector<int>>&dp){
        if(index==prices.size())return 0;
        if(dp[index][buy]!=-1)return dp[index][buy];
        int profit;
        if(buy){
            profit = max(-prices[index]+profits(prices,index+1,0,dp),0+profits(prices,index+1,1,dp));
        }else{
            profit = max(prices[index]+profits(prices,index+1,1,dp),profits(prices,index+1,0,dp));
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return profits(prices,0,1,dp);
    }
};

tabulated 
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(2,-1));
        int n = prices.size();
        dp[n][0]=0;
        dp[n][1]=0;
        for(int index=n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    dp[index][buy] = max(-prices[index]+dp[index+1][0],dp[index+1][1]);
                }else{
                    dp[index][buy] = max(prices[index]+dp[index+1][1],dp[index+1][0]);
                }
            }
        }
        return dp[0][1];
    }
};

1d array

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>ahead(2,0);
        int n = prices.size();
        for(int index=n-1;index>=0;index--){
            vector<int>curr(2,0);
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    curr[buy] = max(-prices[index]+ahead[0],ahead[1]);
                }else{
                    curr[buy] = max(prices[index]+ahead[1],ahead[0]);
                }
            }
            ahead=curr;
        }
        return ahead[1];
    }
};


4 variables only
class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int aheadBuy = 0;
        int aheadNotBuy = 0;

        for(int index = prices.size()-1;
            index >= 0;
            index--) {

            int currBuy = max(

                -prices[index] + aheadNotBuy,

                aheadBuy
            );

            int currNotBuy = max(

                prices[index] + aheadBuy,

                aheadNotBuy
            );

            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }

        return aheadBuy;
    }
};