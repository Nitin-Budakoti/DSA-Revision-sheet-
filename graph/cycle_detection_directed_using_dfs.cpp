#include<iostream>
#include<unordered_map>
#include<list>
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
    bool is_cycle_directed_graph_using_dfs(int src,unordered_map<int,bool>&isvisited,unordered_map<int,bool>&dfsvisited){
        isvisited[src] = true;
        dfsvisited[src] = true;
        for(auto nbr: adjList[src]){
            int val = nbr.first;
            if(!isvisited[val]){
                bool nextAns= is_cycle_directed_graph_using_dfs(val,isvisited,dfsvisited);
                if(nextAns) return true;
            }
            else if(isvisited[val] && dfsvisited[val]) return true;
        }
        dfsvisited[src] = false;
        return false;
    }

};
int main(){
    Graph g;
    g.addList(0,1,3,1);
    g.addList(1,6,7,1);
    g.addList(1,5,4,1);
    g.addList(6,5,6,1);
    g.addList(1,2,9,1);
    g.addList(2,3,9,1);
    g.addList(3,7,9,1);
    g.addList(7,8,9,1);
   // g.addList(8,3,9,1);
    g.addList(3,4,9,1);
    g.printGraph();
    unordered_map<int,bool>isvisited;
    unordered_map<int,bool>dfsvisited;
     if(g.is_cycle_directed_graph_using_dfs(0,isvisited,dfsvisited)){
        cout<<"given graph have cycle detected"<<endl;
     }
     else{
        cout<<"given graph have no cycle"<<endl;
     }
    return 0;
}