/*
947. Most Stones Removed with Same Row or Column
Solved
Medium
Topics
premium lock icon
Companies
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
 

*/

/*
solution using disjoint set :

class  DisjointSet{
    public:
    int n ; 
    vector<int>rank,size,parent;
    DisjointSet(int n){
            rank.resize(n,0);
        parent.resize(n,0);
          size.resize(n,1);
    
        for(int i =0 ;i<n;i++){
            parent[i]=i;
        }
    }
        int find_parent(int node){
            if(node==parent[node]) return node;
            return parent[node] = find_parent(parent[node]);
        }
        void unionBySize(int u , int v){
            int p_u = find_parent(u);
            int p_v = find_parent(v);
            if(p_u == p_v) return ;
            if(size[p_u]<size[p_v]){
                parent[p_u] = p_v;
                size[p_v]+= size[p_u];
            }
            else{
                parent[p_v] = p_u;
                size[p_u]+=size[p_v];
            }
        }


    
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int mx_row = 0;
        int mx_col = 0;
        for(auto it: stones){
            mx_row = max(mx_row , it[0]);
            mx_col = max(mx_col , it[1]);
        }
        DisjointSet ds(mx_row+mx_col+2);
        unordered_map<int , int>mp;
        int n =0;
        for(auto it : stones){
            int nodeRaw= it[0];
            int nodeCol= it[1]+mx_row+1;
            
            ds.unionBySize(nodeRaw,nodeCol);
            mp[nodeRaw]=1;
            mp[nodeCol]=1;
            n++;
        }
        int cnt = 0;
        for(auto it : mp){
            if(ds.find_parent(it.first)== it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};

*/