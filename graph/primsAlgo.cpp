/*class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        unordered_map<int,list<pair<int,int>>>adj;
        for(int i = 0 ; i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        unordered_map<int,bool>visited;
        int sum= 0; 
        while(!pq.empty()){
            auto topNode = pq.top();
            pq.pop();
            int wt= topNode.first;
            int node= topNode.second;
            if(visited[node]==true) continue;
            visited[node]=true;
            sum+=wt;
            for(auto nbr: adj[node]){
                int w = nbr.second;
                int v = nbr.first;
                if(visited[v]==0){
                    pq.push({w,v});
                }
                
            }
        }
        return sum;
    }
};


*/