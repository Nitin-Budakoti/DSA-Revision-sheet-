#include<unordered_map>
#include<iostream>
#include<queue>
using namespace std;
class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // using kahn's algorithm 
        // making adjacency list 
         unordered_map<int,list<int>>adj;
         int n =  edges.size();
         for(int i = 0 ; i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
         }
         //  finding indegree of all vertecs
         vector<int>indgree(V);
         for(auto i:adj){
             for(auto j: i.second){
                 indgree[j]++;
             }
         }
         // push the vertecis having indegree 0 to queue
         queue<int>q;
         for(int i=0; i<V;i++){
             if(indgree[i]==0){
                 q.push(i);
             }
         }
         // bfs logic with minute changes
         vector<int>ans;
        while(!q.empty()){
            int fnode= q.front();
            q.pop();
            ans.push_back(fnode);
            for(auto nbr: adj[fnode]){
                indgree[nbr]--;
                if(indgree[nbr]==0) q.push(nbr);
            }
        }
         return ans;
        
    }
};
int main(){
    return  0;
}