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

};
int main(){
    Graph g;
    g.addList(0,1,3,1);
    g.addList(0,3,7,1);
    g.addList(1,2,4,1);
    g.addList(1,3,6,1);
    g.addList(2,3,9,1);
    g.printGraph();
    return 0;
}