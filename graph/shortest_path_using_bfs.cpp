#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;
// adjacency list implementation
class Graph{
    unordered_map<int,list<pair<int,int>>>adjList;
    public:
    void addList(int u , int v, int d , bool direction){ //  d for distance between them
        // connect u to v
        adjList[u].push_back({v,d});
        if(!direction){
            adjList[v].push_back({u,d});
        }
    }
    void printGraph(){
        for(auto nodes: adjList){
            cout<<nodes.first<<"-> "<<" ";
            for(auto nbr: nodes.second){
                cout<<"{"<<nbr.first<<" , "<< nbr.second<<"}";
            }
            cout<<endl;
        }
    }
    vector<int>shortest_bfs(int src, int dest,unordered_map<int,bool>&visited){
        queue<int>q;
        q.push(src);
        visited[src]=true;
        unordered_map<int,int>parent;
        parent[src] =-1;
        while(!q.empty()){
            int f_node= q.front();
            q.pop();
            for(auto nbr: adjList[f_node]){
                if(!visited[nbr.first]){
                    q.push(nbr.first);
                    parent[nbr.first] = f_node;
                    visited[nbr.first] = true;
                }
            }
        }
        vector<int>ans;
        int val =dest;
        while(val != -1){
            ans.push_back(val);
            val = parent[val];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

};
int main(){
    Graph g;
    g.addList(0,1,1,0);
    g.addList(0,2,1,0);
    g.addList(0,3,1,0);
    g.addList(1,4,1,0);
    g.addList(2,5,1,0);
    g.addList(3,6,1,0);
    g.addList(4,5,1,0);
    g.addList(6,5,1,0);
    int src =0;
    int dest = 5;

    g.printGraph();
    unordered_map<int,bool>isvisited;
    vector<int> s_path = g.shortest_bfs(src,dest,isvisited);
    cout<<endl<<"shortest path betweem src and dest is"<<endl;
    for(auto val:s_path){
        cout<<val<<"->";
    }
    return 0;
}
// for finding the shortest path to every node 

/*
 vector<int> shortestPath(vector<vector<int>>& adj, int src) {
    int n = adj.size();
    vector<int>ans(n,-1);
     queue<int>q;
     q.push(src);
     ans[src] =0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbr: adj[node]){
                if(ans[nbr]==-1){
                    ans[nbr]= ans[node]+1;
                    q.push(nbr);
                }
            }
        }
        return ans;
    }
};
*/