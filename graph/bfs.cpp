#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
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
    void bfs(int src, unordered_map<int,bool>&isvisited){
        queue<int>q;
        q.push(src);
       ;
        isvisited[src] = true;
        while(!q.empty()){
            int front_node = q.front();
            q.pop();
            cout<<front_node<<" -> ";
            for(auto nbr: adjList[front_node]){
                if(!isvisited[nbr.first]){
                        q.push(nbr.first);
                        isvisited[nbr.first] = true; 
                }
            } 

        }

    }

};
int main(){
    Graph g;
    g.addList(0,1,3,0);
    g.addList(1,2,3,0);
    g.addList(1,3,3,0);
    g.addList(3,5,3,0);
    g.addList(3,7,3,0);
    g.addList(7,6,3,0);
    g.addList(7,4,3,0);
    g.addList(8,9,3,0);
       g.printGraph();
        cout<<endl;
          cout<<"Bfs of graph is "<<endl;
    unordered_map<int,bool>isvisited;
    // loop using for disconnected graph 
    for(int i = 0 ;i<=8;i++){
        if(! isvisited[i])
        g.bfs(i,isvisited);
    }
 
   
  
    
    return 0;
}