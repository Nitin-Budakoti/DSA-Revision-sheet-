/*
You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
Note : An island means group of 1s such that they share a common side.

 

Example 1:

Input: n = 4
m = 5
k = 4
A = {{1,1},{0,1},{3,3},{3,4}}

Output: 1 1 2 2
Explanation:
0.  00000
    00000
    00000
    00000
1.  00000
    01000
    00000
    00000
2.  01000
    01000
    00000
    00000
3.  01000
    01000
    00000
    00010
4.  01000
    01000
    00000
    00011
*/

//Solution :--
/*

// User function Template for C++
 class disjointSet{ 
     vector<int>Parent;
      vector<int>Size;
     public:
        disjointSet( int n ){
            Parent.resize(n,0);
            Size.resize(n,1);
            for(int i = 0 ; i<n;i++){
                Parent[i]=i;
            }
        }
        int find_parent(int n){
            if(n == Parent[n]) return n;
            return  Parent[n] = find_parent(Parent[n]);
        }
        void unionSize(int x, int y){
            int px= find_parent(x);
            int py= find_parent(y);
            if(px==py) return ;
            if(Size[px]<Size[y]){
                Parent[px] = py;
                Size[py]+=Size[px];
            }
            else{
                Parent[py] = px;
                Size[px]+=Size[py];
            }
        }
        bool isConnected(int x , int y){
            int px = find_parent(x);
            int py = find_parent(y);
            return px==py;
            
        }
     
 };
    
class Solution {
    private:
    bool is_valid(int nr , int nc ,int n , int m){
        return nr>=0 && nr<n && nc>=0 && nc<m;
    }
  public:``
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here

        disjointSet ds(n*m);
        map<pair<int,int>,bool>isvisited;
        int cnt = 0 ;
         vector<int>ans;
         for(auto it : operators){
             int row = it[0];
             int col = it[1];
             if(isvisited[{row,col}]){
                 ans.push_back(cnt);
                 continue;
             }
             
             
             cnt++;
             isvisited[{row,col}]= true;
             
              
                 int dx[] = {0,0,1,-1};
                 int dy[] = {1,-1,0,0};
                 for(int ind = 0 ;ind<4;ind++){
                     int n_r = dx[ind]+row;
                     int n_c = dy[ind]+col;
                     if(is_valid(n_r,n_c,n,m)){
                        if(isvisited[{n_r,n_c}] ){
                            int node = row*m+col;
                            int nbrNode= n_r*m+n_c;
                            if(!ds.isConnected(node,nbrNode)){
                                ds.unionSize(node,nbrNode);
                                cnt--;
                            }
                        }
                        
                     }
                 }
                 ans.push_back(cnt);
         }
         return ans;
    }
};

*/