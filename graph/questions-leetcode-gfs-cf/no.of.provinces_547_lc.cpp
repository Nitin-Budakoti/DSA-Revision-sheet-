/* 
Description of question 
\There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.


// solution 1 : directly apply dfs on matrix :
class Solution {
public:
    void dfs(int src, unordered_map<int,bool>&isvisited, vector<vector<int>>& isConnected){
        isvisited[src] = true;
        int siz = isConnected[src].size();
        for(int i = 0 ; i<siz;i++){
            if(i!=src && isConnected[src][i]==1){
                if(!isvisited[i]){
                    dfs(i,isvisited,isConnected);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool>isvisited;
        int count =0;
        int n = isConnected.size();
        for(int i = 0 ; i<n;i++){
            if(!isvisited[i]){
                dfs(i,isvisited,isConnected);
                count++;
            }
        }
        return count;

    }
};



// solution 2 : convert the matrix into adjlist then apply dfs :


class Solution {
public:
    void dfs(int src, unordered_map<int,bool>&isVisited,unordered_map<int,list<int>>&adj){
        isVisited[src]=true;
        for(auto nbr: adj[src]){
            if(!isVisited[nbr]){
                dfs(nbr,isVisited,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         unordered_map<int,list<int>>adj;
         int n = isConnected.size();
         int m = isConnected[0].size();
         for(int i = 0 ; i< n;i++){
            for(int j = 0 ;j<m;j++){
                if(isConnected[i][j]==1){
                    adj[i].push_back(j);
                }
            }
         }
         unordered_map<int,bool>isVisited;
         int ans= 0;
         for(int i = 0; i<n;i++){
            if(! isVisited[i] ){
                dfs(i,isVisited,adj);
                ans++;
            }
         }
         return ans;
    }
};


*/