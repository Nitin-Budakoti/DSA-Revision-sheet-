// Problem statement:
// Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

// Examples:

// Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
// Output: 3
// Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

// solution 
/*
class Solution {
  public:
    int solveRe(vector<int>&arr,int sum,int index){
        //base case
        // handling of zero
        if(index==0){
            if(sum==0 && arr[0] ==0 ) return 2;
            if(sum==0 || arr[0]==sum) return 1;
            return 0;
        }
        int include = 0;
        if(arr[index]<=sum){
            include = solveRe(arr,sum-arr[index],index-1);
        }
        int exclude = solveRe(arr,sum,index-1);
        return include + exclude;
    }
    int solveMemo(vector<int>&arr,int sum,int index,vector<vector<int>>&dp){
        //base case
        // handling of zero
        if(index==0){
            if(sum==0 && arr[0] ==0 ) return 2;
            if(sum==0 || arr[0]==sum) return 1;
            return 0;
        }
        // checking before execution 
        if(dp[index][sum]!= -1) return dp[index][sum];
        int include = 0;
        if(arr[index]<=sum){
            include = solveMemo(arr,sum-arr[index],index-1,dp);
        }
        int exclude = solveMemo(arr,sum,index-1,dp);
        return dp[index][sum]= include + exclude;
    }
    int solveTab(vector<int>&arr,int target,int n){
        vector<vector<int>>dp(n+1,vector<int>(target+1,0));
       if (arr[0] == 0)
        dp[0][0] = 2; // Two ways: include or exclude 0
         else
        dp[0][0] = 1; // One way: exclude only

          if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1; 
        for(int i = 1 ;i<n;i++){
            for(int j = 0 ; j<= target;j++){
          int include = 0;
                if(arr[i]<=j)
                    include= dp[i-1][j-arr[i]];
                int exclude = dp[i-1][j];   
                 dp[i][j] = include +exclude;
            }
                    
        }
        return dp[n-1][target];
        
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>>dp(n+2,vector<int>(target+1,-1));
        int ans = solveTab(arr,target,n);
        return ans;
    }
};

*/



