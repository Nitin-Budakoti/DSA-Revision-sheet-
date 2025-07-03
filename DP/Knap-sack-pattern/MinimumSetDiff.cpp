// Problem statement:
// Given an array arr[]  containing non-negative integers, the task is to divide it into two sets set1 and set2 such that the absolute difference between their sums is minimum and find the minimum difference.

// Examples:

// Input: arr[] = [1, 6, 11, 5]
// Output: 1
// Explanation: 
// Subset1 = {1, 5, 6}, sum of Subset1 = 12 
// Subset2 = {11}, sum of Subset2 = 11 
// Hence, minimum difference is 1.  
// solution:

/*
class Solution {
    void solve(vector<int>&arr,int n ,int target, vector<int>&store){
        vector<vector<bool>>dp(n+1,vector<bool>(target+1,0));
        dp[0][0] =1;
        if(arr[0]<=target){
            dp[0][arr[0]]=1;
        }
        for(int i=1; i<n;i++){
            for(int j = 0 ; j<=target;j++){
                bool include = 0;
                if(j>=arr[i])
                    include = dp[i-1][j-arr[i]];
                bool exclude = dp[i-1][j];  
                dp[i][j]= include || exclude;
            }
        }
        for(int i = 0 ; i<=target;i++){
            if(dp[n-1][i]==1)
                store.push_back(i);
        }
        
    }
  public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        int range= accumulate(arr.begin(),arr.end(),0);
        int main_range = range/2;
        vector<int>store;
        solve(arr,n,main_range,store);
        int ans = INT_MAX;
        for(auto it : store)
            ans = min(ans, range - 2*it);
    
        return ans;
        
    }
    
};

*/