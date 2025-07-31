/*
Description :
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1


solution : we are using bfs and finding the no of iland:

class Solution {
public:
    void bfs(int i , int j ,  vector<vector<int>>&visited,vector<vector<char>>& grid){
        visited[i][j] =1;
        queue<pair<int,int>>q;
         int n = grid.size();
        int m = grid[0].size();
        q.push({i,j});
        while(!q.empty()){
            int c_row =  q.front().first;
            int c_col =  q.front().second;
            q.pop();
            int dx[] ={-1,0,1,0};
            int dy[] ={0,1,0,-1};
            for(int i = 0 ; i<4;i++){
                int n_row = c_row+dx[i];
                int n_col= c_col+dy[i];
                if(n_row>=0 && n_row< n  && n_col >=0 && n_col<m && grid[n_row][n_col]=='1' &&visited[n_row][n_col]==0){
                    q.push({n_row,n_col});
                    visited[n_row][n_col]= true;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int land  =0;
        for(int i =0;i<n;i++){
            for(int j = 0 ; j<m;j++){
                if(visited[i][j] == 0 && grid[i][j]=='1'){
                    bfs(i,j,visited,grid);
                     land++;
                }
            }
        }
        return land;
    }
};



*/