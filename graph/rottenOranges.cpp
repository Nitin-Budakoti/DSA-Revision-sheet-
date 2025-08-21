// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         queue<pair<pair<int,int>,int>>q;
//         // insert all rotten oranges into queue with time 0 
//         int n = grid.size();
//         int m = grid[0].size();
//         for(int i = 0 ; i< n ; i++){
//             for(int j = 0 ;j <m ;j++){
//                 if(grid[i][j]==2){
//                     q.push({{i,j},0});
//                 }
//             }
//         }
//         int time = 0; 
//         while(!q.empty()){

//             auto fnode = q.front();
//             q.pop();
//             int r = fnode.first.first;
//             int c  = fnode.first.second;
//             int t = fnode.second;
//             int dx[] = {1,0,-1,0};
//             int dy[] = {0,1,0,-1};
//             for(int  i = 0; i< 4;i++){
//                 int nr = r+dx[i];
//                 int nc =  c + dy[i];
//                 if(nr>=0 && nr< n && nc>=0 && nc <m && grid[nr][nc]==1){
//                     time = max(time, t+1);
//                     q.push({{nr,nc},t+1});
//                     grid[nr][nc]= 2;
//                 }
//             }
//         }

//      for(int i = 0 ; i< n ; i++){
//             for(int j = 0 ;j <m ;j++){
//                 if(grid[i][j]==1){
//                     return -1;
//                 }
//             }
//         }
//         return time;

        
//     }
// };