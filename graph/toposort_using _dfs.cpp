 #include<unordered_map>
#include<iostream>
#include<queue>s
#include<stack>
using namespace std;

 class Solution {
  public:
  void dfstopo(int src, unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj,stack<int>&s){
        visited[src]=true;
        for(auto nbr: adj[src]){
            if(!visited[nbr]){
                dfstopo(nbr,visited,adj,s);
            }
        }
        s.push(src);
  }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        //using dfs approach       
        // making adjacency list 
         unordered_map<int,list<int>>adj;
         int n =  edges.size();
         for(int i = 0 ; i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
         }
         stack<int>s;
         unordered_map<int,bool>visited;    
         for(int i =0;i<V;i++){
             if(!visited[i])
                dfstopo(i,visited,adj,s);   
         }
         
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};