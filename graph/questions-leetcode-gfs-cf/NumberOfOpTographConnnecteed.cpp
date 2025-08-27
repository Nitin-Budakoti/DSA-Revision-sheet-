/*
1319. Number of Operations to Make Network Connected
Solved
Medium
Topics
premium lock icon
Companies
Hint
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.


solution we simply use the disjoint set here \\\\



class DisjointSet {
vector<int>rank,size,parent;
public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i =0 ;i<n+1;i++){
            parent[i] =i;
        }
    }

    bool find(int u, int v) {
     int pu = findParent(parent,u);
     int pv = findParent(parent,v);
     if(pu==pv) return true;
     return false;
    }
    int findParent(vector<int>&parent,int x){
        if(parent[x]==x)return x;
        return parent[x] = findParent(parent,parent[x]);
    }

    void unionByRank(int u, int v) {
     int pu = findParent(parent,u);
     int pv= findParent(parent,v);
     int pur = rank[pu];
     int pvr = rank[pv];
     if(pur<pvr){
        parent[pu] = pv;
     }
     else if(pur>pvr){
        parent[pv] = pu;
     }
     else{
        parent[pv]=pu;
        rank[pu]++;
     }
    }
    int findComponent(int n){
        int c=0;
        for(int i = 0 ; i<n;i++){
             if (findParent(parent, i) == i) c++;
        }
        return c;
    }
};
//  main function of leet code;-
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra = 0;
           for(int i = 0 ; i<connections.size();i++){
            int u= connections[i][0];
            int v =connections[i][1];
            if(ds.find(u,v)){
                extra++;
            }
            else{
                ds.unionByRank(u,v);
            }
           }
           int c = ds.findComponent(n);
           if(extra < c-1) return -1;
           return c-1;
    }
};

*/