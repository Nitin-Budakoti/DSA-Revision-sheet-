
// Question statement:

// Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 

// Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

// Examples :

// Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
// Output: 3
// Explanation: Choose the last item, which weighs 1 unit and has a value of 3.

// Solution :

/*


class Solution {
  public:
    int solveRe(int W, vector<int> &val, vector<int> &wt, int index){
        //base case
        if(index==0){
            if(wt[0]<=W){
                return val[0];
            }
            else return 0;
        }
        int include= 0;
        if(wt[index]<= W)
            include = val[index] + solveRe(W-wt[index],val,wt,index-1);
        int exclude = 0 + solveRe(W,val,wt,index-1);
        return max(include,exclude);
        
    }
    int solveMemo(int W, vector<int> &val, vector<int> &wt, int index,vector<vector<int>>&dp){
        //base case
        if(index==0){
            if(wt[0]<=W){
                return val[0];
            }
            else return 0;
        }
        // dp check 
        if(dp[index][W]!=-1) return dp[index][W];
        int include= 0;
        if(wt[index]<= W)
            include = val[index] + solveMemo(W-wt[index],val,wt,index-1,dp);
        int exclude = 0 + solveMemo(W,val,wt,index-1,dp);
        return dp[index][W] =  max(include,exclude);
    }
    
    int solveTab(int W, vector<int> &val, vector<int> &wt ,int n){
        vector<vector<int>>dp(n+1 , vector<int>(W+1,0));
        for(int w = wt[0] ;w<=W;w++){
            dp[0][w] = val[0];
        }
        for(int index = 1 ; index<n;index++){
            for(int w = 0 ; w<=W; w++){
                int include= 0;
                    if(wt[index]<= w)
                        include = val[index] + dp[index-1][w-wt[index]];
                    int exclude = 0 + dp[index-1][w];
                dp[index][w] = max(include,exclude);    
            }
        }
        return dp[n-1][W];
    }
    
      int solveOp(int W, vector<int> &val, vector<int> &wt ,int n){
        //vector<vector<int>>dp(n+1 , vector<int>(W+1,0));
        vector<int>prev(W+1,0);
        vector<int>curr(W+1,0);
        for(int w = wt[0] ;w<=W;w++){
           prev[w] = val[0];
        }
        for(int index = 1 ; index<n;index++){
            for(int w = 0 ; w<=W; w++){
                int include= 0;
                    if(wt[index]<= w)
                        include = val[index] + prev[w-wt[index]];
                    int exclude = 0 + prev[w];
                curr[w] = max(include,exclude);    
            }
            prev = curr;
        }
        return prev[W];
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        //vector<vector<int>>dp(n+2, vector<int>(W+1,-1));
        int ans = solveTab(W,val,wt ,n);
        return ans;
    }
};
*/
  