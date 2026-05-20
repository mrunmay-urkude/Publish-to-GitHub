basic recursion and memoization

class Solution {
    public:
        int kaal(vector<int>& prices,int bought,int index, int buy,vector<vector<vector<int>>>&dp){
            if(bought==2||index==prices.size())return 0;
            if(dp[index][buy][bought]!=-1)return dp[index][buy][bought];
            int profit;
            if(buy){
                profit=max(-prices[index]+kaal(prices,bought,index+1,0,dp),kaal(prices,bought,index+1,1,dp));
            }else{
                profit=max(prices[index]+kaal(prices,bought+1,index+1,1,dp),kaal(prices,bought,index+1,0,dp));
            }
            return dp[index][buy][bought]=profit;

        }
        int maxProfit(vector<int>& prices){
            vector<vector<vector<int>>>dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
            return kaal(prices,0,0,1,dp);
        }
    };


tabulation
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(2,vector<int>(3, 0)));
        for(int index = n-1;index >= 0;index--) {
            for(int buy = 0;buy <= 1;buy++) {
                for(int cap = 1;cap <= 2;cap++){
                    if(buy) {
                        dp[index][buy][cap] = max(-prices[index]+ dp[index+1][0][cap],dp[index+1][1][cap]);
                    }
                    else{
                        dp[index][buy][cap] = max(prices[index]+ dp[index+1][1][cap-1],dp[index+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};
2d optimization

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> after(2,vector<int>(3, 0));
        for(int index = n-1;index >= 0;index--) {
           vector<vector<int>> curr(2,vector<int>(3, 0)); 
            for(int buy = 0;buy <= 1;buy++) {
                for(int cap = 1;cap <= 2;cap++){
                    if(buy) {
                        curr[buy][cap] = max(-prices[index]+ after[0][cap],after[1][cap]);
                    }
                    else{
                        curr[buy][cap] = max(prices[index]+ after[1][cap-1],after[0][cap]);
                    }
                }
            }
            after=curr;
        }
        return after[1][2];

    }
}; 







/////////////////////////////////////////////////////////////////////////////////
coverting this in the transaction_safe
class Solution {
public:
    int solve(vector<int>& prices,
          int index,
          int transaction){

    if(index == prices.size()
       || transaction == 4)
        return 0;

    if(transaction % 2 == 0){

        return max(

            -prices[index]
            + solve(prices,
                    index+1,
                    transaction+1),

            solve(prices,
                  index+1,
                  transaction)
        );
    }

    else{

        return max(

            prices[index]
            + solve(prices,
                    index+1,
                    transaction+1),

            solve(prices,
                  index+1,
                  transaction)
        );
    }
}
    int maxProfit(vector<int>& prices) {
       return solve(prices,0,0);      
    }
};

// ========================================
// MEMOIZATION
// TC -> O(N*4)
// SC -> O(N*4) + recursion stack
// ========================================

class Solution {
public:

    int solve(
        vector<int>& prices,
        int index,
        int transaction,
        vector<vector<int>>& dp
    ) {

        if(index == prices.size()
           || transaction == 4)
            return 0;

        if(dp[index][transaction] != -1)
            return dp[index][transaction];

        if(transaction % 2 == 0) {

            return dp[index][transaction] = max(

                -prices[index]
                + solve(
                    prices,
                    index+1,
                    transaction+1,
                    dp
                ),

                solve(
                    prices,
                    index+1,
                    transaction,
                    dp
                )
            );
        }

        return dp[index][transaction] = max(

            prices[index]
            + solve(
                prices,
                index+1,
                transaction+1,
                dp
            ),

            solve(
                prices,
                index+1,
                transaction,
                dp
            )
        );
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(
            n,
            vector<int>(4, -1)
        );

        return solve(
            prices,
            0,
            0,
            dp
        );
    }
};


// ========================================
// TABULATION
// TC -> O(N*4)
// SC -> O(N*4)
// ========================================

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<vector<int>> dp(
            n + 1,
            vector<int>(5, 0)
        );

        for(int index = n-1;
            index >= 0;
            index--) {

            for(int transaction = 3;
                transaction >= 0;
                transaction--) {

                if(transaction % 2 == 0) {

                    dp[index][transaction] = max(

                        -prices[index]
                        + dp[index+1][transaction+1],

                        dp[index+1][transaction]
                    );
                }

                else {

                    dp[index][transaction] = max(

                        prices[index]
                        + dp[index+1][transaction+1],

                        dp[index+1][transaction]
                    );
                }
            }
        }

        return dp[0][0];
    }
};

// ========================================
// SPACE OPTIMIZED
// TC -> O(N*4)
// SC -> O(4)
// ========================================

class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        vector<int> after(5, 0);

        for(int index = n-1;
            index >= 0;
            index--) {

            vector<int> curr(5, 0);

            for(int transaction = 3;
                transaction >= 0;
                transaction--) {

                if(transaction % 2 == 0) {

                    curr[transaction] = max(

                        -prices[index]
                        + after[transaction+1],

                        after[transaction]
                    );
                }

                else {

                    curr[transaction] = max(

                        prices[index]
                        + after[transaction+1],

                        after[transaction]
                    );
                }
            }

            after = curr;
        }

        return after[0];
    }
};


the most optimized

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int sell1 = 0, sell2 = 0;
        for (int price : prices) {
            buy1 = min(buy1, price);
            sell1 = max(sell1, price - buy1);
            buy2 = min(buy2, price - sell1);
            sell2 = max(sell2, price - buy2);
        }
        return sell2;
    }
};