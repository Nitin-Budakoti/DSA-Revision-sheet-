// Problem statement:
// Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.

// Note: Each element must be in exactly one subset.

// Examples:

// Input: arr = [1, 5, 11, 5]
// Output: true
// Explanation: The two parts are [1, 5, 5] and [11].

// solution 

/*
class Solution {
  public:
    bool solveRe(vector<int>& arr, int sum,int index){
        //base condition
        if(index==0){
            if(arr[0] == sum) return true;
            else if(sum==0) return true;
            else return false;
        }
        bool include = false;
         if(arr[index]<=sum)
            include = solveRe(arr,sum-arr[index],index-1);
        bool exclude = solveRe(arr,sum,index-1);
        return include || exclude;
    }
     bool solveMemo(vector<int>& arr, int sum,int index,vector<vector<int>>&dp){
        if(index==0){
            if(arr[0] == sum) return true;
            else if(sum==0) return true;
            else return false;
        }
        //third step before going to check anser in dp
        if(dp[index][sum]!=-1) return dp[index][sum];
        bool include = false;
         if(arr[index]<=sum)
            include = solveMemo(arr,sum-arr[index],index-1,dp);
        bool exclude = solveMemo(arr,sum,index-1,dp);
        //second step store anser in dp
        return dp[index][sum] =  include || exclude;
    }
    bool solveTab(vector<int>& arr, int sum,int n){
         vector<vector<bool>>dp(n+1,vector<bool>(sum+1,0));
         //initialization of dp
         for(int i = 0 ; i<=n;i++){
             dp[i][0] = true;
         }
         dp[0][arr[0]] = true;
         for(int i = 1 ;i<n;i++){
            for(int j = 0 ;j<=sum;j++){
                bool include = false;
                 if(arr[i]<=j)
                    include = dp[i-1][j-arr[i]];
                bool exclude =dp[i-1][j];
                dp[i][j] = include || exclude;
            }
         }
         return  dp[n-1][sum];
    }
      bool solveOp(vector<int>& arr, int sum,int n){
        // vector<vector<bool>>dp(n+1,vector<bool>(sum+1,0));
         //initialization of dp
         vector<bool>prev(sum+1,0);
         vector<bool>curr(sum+1,0);
        prev[0] = true;
         if (arr[0] <= sum)
               prev[arr[0]] = true;
         for(int i = 1 ;i<n;i++){
            for(int j = 0 ;j<=sum;j++){
                bool include = false;
                 if(arr[i]<=j)
                    include = prev[j-arr[i]];
                bool exclude =prev[j];
                curr[j] = include || exclude;
            }
            prev = curr;
         }
         return  prev[sum];
    }
    
    bool equalPartition(vector<int>& arr) {
        int sum = accumulate(arr.begin(),arr.end(),0);
        if(sum%2!=0) return false;
        //for even case 
        int target = sum/2;
        int n = arr.size();
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solveOp(arr,target,n);
        
        
        
    }
}
*/