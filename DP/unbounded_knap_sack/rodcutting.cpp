// problem statement 
/*
Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: n = size of price, and price[] is 1-indexed array.
*/
//solution 

/*
// User function Template for C++

class Solution {
  public:
    int solve(vector<int>&price , vector<int>&peice,int i ,int rod,vector<vector<int>>&dp ){
        //base case 
        if(i<0) return 0;
        if(rod<=0) return 0;
        if(dp[i][rod]!=-1) return dp[i][rod];
        int take = 0;
        if(rod>=peice[i])
            take = price[i]+solve(price,peice,i,rod-peice[i],dp);
        int notake =solve(price,peice,i-1,rod,dp);
        return dp[i][rod] = max(take,notake);
    }
    int solveTab(vector<int>&price, vector<int>&peice ,int n ){
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i = 0 ;i<=n;i++){
            dp[0][i] = i*price[0]; 
        }
        for(int i = 1 ;i<n;i++){
            for(int j = 0 ; j<=n;j++){
                int take = 0 ; 
                if(j>=peice[i]) take = price[i]+dp[i][j-peice[i]];
                int notake = dp[i-1][j];
                dp[i][j] = max(take,notake);
            }
        }
    return dp[n-1][n];
    }
    
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int>peice(n);
        for(int i = 0 ; i<n;i++){
            peice[i] = i+1; 
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveTab(price,peice,n);
    }
};

*/