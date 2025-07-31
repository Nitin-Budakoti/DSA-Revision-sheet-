// #include <bits/stdc++.h> 
// vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
//   // step one making adjecency matrix: 
//    unordered_map<int,list<pair<int,int>>>adj;
//    for(int i = 0 ; i<edges;i++){
//       int u = vec[i][0];
//       int v = vec[i][1];
//       int w = vec[i][2];
//       adj[u].push_back(make_pair(v,w));
//       adj[v].push_back(make_pair(u,w));
//    }
//    // make a set and distance array 
//    set<pair<int,int>>st;
//    vector<int>dist(vertices,INT_MAX);
//    // mark source node 0 and insrt it into set
//    dist[0]=0;
//    st.insert(make_pair(0,0));

//    // logic like bfs : 
//    while(!st.empty()){
//       //fetch smallest node of begin node: 
//       auto top = *(st.begin());
//       int node = top.second;
//       int nodeDistance = top.first;
//       st.erase(st.begin());
//       // traverse in the  neighbours:
//       for(auto nbr : adj[node]){
//          if(nodeDistance + nbr.second < dist[nbr.first]){
//             // find if in set
//             auto record = st.find(make_pair(dist[nbr.first],nbr.first));
//             if(record != st.end()){
//                st.erase(record);
//             }
//             // update new  small distance : 
//             dist[nbr.first] = nodeDistance + nbr.second;
//             // also update in the set record : 
//             st.insert(make_pair( dist[nbr.first],nbr.first));
//          }
//       }
//    }
//    return dist;
   
// }
