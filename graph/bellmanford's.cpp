/* Gfg practise :- 
// User function Template for C++
const int VAL = 100000000;
class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        //converting the input format into adjacency list'
        unordered_map<int,list<pair<int,int>>>adj;
        int n=  edges.size();
        for(int i = 0 ; i<n;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(V,VAL);
        dist[src]=0;
        for(int i =  0 ; i<V-1;i++){
            for(auto  t : adj){
                for(auto nbr : t.second){
                    int u = t.first;
                    int v = nbr.first;
                    int w = nbr.second;
                    // relaxation step
                    if(dist[u]!=VAL && dist[u]+w<dist[v]){
                        dist[v]= dist[u]+w;
                    }
                }
            }
        }
        for(auto  t : adj){
                for(auto nbr : t.second){
                    int u = t.first;
                    int v = nbr.first;
                    int w = nbr.second;
                    // relaxation step
                    if(dist[u]!=VAL && dist[u]+w<dist[v]){
                        return {-1};
                    }
                }
            }
        return dist;
        
    }
};

*/