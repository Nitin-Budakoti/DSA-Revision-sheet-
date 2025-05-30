// Problem statement:
// Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

// Examples :

// Input: arr[] =  [5, 2, 6, 4], d = 3
// Output: 1
// Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.

// solution:

/*
class Solution {
  public:
    int solve(vector<int>&arr , int target , int n){
        vector<vector<int>>dp(n+1, vector<int>(target+1,0));
        if(arr[0] == 0){
            // for handling 0 case
            dp[0][0] = 2;
        }
        else{
            dp[0][0]=1;
        }
        if(arr[0]<=target && arr[0]!=0){
            dp[0][arr[0]] =1;
        }
        for(int i = 1 ; i<n;i++){
            for(int j = 0 ;j<=target;j++){
                int include = 0;
                if(j>=arr[i])
                    include =  dp[i-1][j-arr[i]];
                int exclude= dp[i-1][j];
                dp[i][j] = include +exclude;
            }
        }
        return dp[n-1][target];
    }
    int countPartitions(vector<int>& arr, int d) {
    // s1 = (diff +total)/2
    
    int total = accumulate(arr.begin(),arr.end(),0);
    if((d+total)%2!=0) return 0;
    int target = (d+total)/2;
    int n = arr.size();
    int ans = solve(arr, target, n);
    return ans;
    }
};
*/