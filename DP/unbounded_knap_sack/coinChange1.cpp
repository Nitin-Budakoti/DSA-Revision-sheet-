// Problem statement
// Given an integer array coins[ ] representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ]. 
// Note: Assume that you have an infinite supply of each type of coin. Therefore, you can use any coin as many times as you want.
// Answers are guaranteed to fit into a 32-bit integer. 

//solution :

/*
class Solution {
  public:
    int solve(vector<int>&coins, int sum , int i,vector<vector<int>>&dp ){
        //base case
        if(sum==0) return 1;
        if(i<0) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take = 0;
        if(coins[i]<=sum)
            take = solve(coins,sum-coins[i],i,dp);
        int notake = solve(coins,sum,i-1,dp);
        return dp[i][sum] =  take+notake;
    }
    int solveTab(vector<int>&coins,int sum, int n){
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i = 0 ; i<n;i++){
            dp[i][0] =1;
        }
        for (int j = 0; j <= sum; j++) {
        if (j % coins[0] == 0) {
            dp[0][j] = 1;
        }
        }
        for(int i = 1;i<n;i++){
            for(int j= 0;j<=sum;j++){
                int take = 0;
                if(j>=coins[i])
                    take = dp[i][j-coins[i]];
                int notake  = dp[i-1][j];
                dp[i][j] = take + notake;
            }
        }
        return dp[n-1][sum];
    }
    int count(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        int ans = solveTab(coins,sum ,n);
        return ans;
    }
};


*/