//problem 
/*
You are given an array coins[], where each element represents a coin of a different denomination, and a target value sum. You have an unlimited supply of each coin type {coins1, coins2, ..., coinsm}.

Your task is to determine the minimum number of coins needed to obtain the target sum. If it is not possible to form the sum using the given coins, return -1.
*/

//solution
/*
class Solution {
  public:
    int solve(vector<int>&coins,int sum, int i,vector<vector<int>>&dp){
        if(i==0){
            if(sum%coins[0]==0) return sum/coins[0];
            return 1e9;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        int take = INT_MAX;
        if(coins[i]<=sum) take =1+ solve(coins,sum-coins[i],i,dp);
        int notake = solve(coins,sum,i-1,dp);
        return dp[i][sum] = min(take,notake);
    }
    int solveTab(vector<int>&coins,int sum , int n ){
        vector<vector<int>>dp(n+1,vector<int>(sum+1,0));
        for(int i = 0 ; i<=sum;i++){
            if( i%coins[0] ==0) dp[0][i] = i/coins[0];
            else dp[0][i] =1e9;
        }
        for(int i = 1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int take = INT_MAX;
                if(j>=coins[i]){
                    take  = 1+dp[i][j-coins[i]];
                }
                int notake = dp[i-1][j];
                dp[i][j] = min(take,notake);
            }
        }
        return dp[n-1][sum];
    }
    int minCoins(vector<int> &coins, int sum) {
        int n = coins.size();
            vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        int ans = solveTab(coins,sum,n);
    
        if(ans!=1e9)
            return ans;
        return -1;
    }
};
*/