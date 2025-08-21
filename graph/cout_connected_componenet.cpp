#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<list>
using namespace std;
  void dfs(int src, unordered_map<int,list<int>>&adj,unordered_map<int,bool>&isvisited){
    isvisited[src]= true;
    for(auto nbr: adj[src]){
      if(!isvisited[nbr]){
        dfs(nbr,adj,isvisited);
      }
    }
  }
int findNumberOfComponent(int V, vector<vector<int>> &edges) {
      unordered_map<int, list<int>> adj;
      int n = edges.size();
      for(int i =0 ; i<n;i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
      }
      int comp = 0 ; 
      unordered_map<int, bool> isvisited; 
      for(int i = 0 ; i<V;i++){
        if(!isvisited[i]){
          dfs(i,adj,isvisited);
          comp++;
        }
      }
      return comp;
    }
    int main(){
        vector<vector<int>>edges = {{0,1},{1,2}};
        int V = 4;
        int ans = findNumberOfComponent(V,edges);
        cout<<ans<<endl;
    }