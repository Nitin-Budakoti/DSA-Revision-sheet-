//  shortest path to all nodes using  dfs+ topo sort
#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<climits>
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
     void dfstopo(int src, unordered_map<int,bool>&visited,stack<int>&s){
        visited[src]=true;
        for(auto nbr: adjList[src]){
            if(!visited[nbr.first]){
                dfstopo(nbr.first,visited,s);
            }
        }
        s.push(src);
    }
    void shortestPath(stack<int>st,int n,vector<int>&distance ){
        int src = st.top();
        st.pop();
        distance[0]=0;
        for(auto nbr: adjList[0]){
            // relaxation step
            if(distance[src]+nbr.second<distance[nbr.first]){
                distance[nbr.first]= distance[src]+nbr.second;
            }
        }
        while(!st.empty()){
            int top_ele = st.top();
            st.pop();
            if(distance[top_ele]!=INT_MAX){
                for(auto nbr: adjList[top_ele]){
                    if(distance[top_ele]+nbr.second<distance[nbr.first]){
                        distance[nbr.first] = distance[top_ele]+nbr.second;
                    }
                }
            }
        }
    }
    
};

int main(){
    Graph g;
    g.addList(0,1,5,1);
    g.addList(0,2,3,1);
    g.addList(1,3,3,1);
    g.addList(2,3,5,1);
    g.addList(2,4,6,1);
    g.addList(2,1,2,1);
    g.addList(4,3,1,1);
    //g.addList(2,2,9,1);
    g.printGraph();
    stack<int>st;
    int n = 5;
    unordered_map<int,bool>visited;
    for(int i = 0; i<n;i++){
        if(!visited[i]){
            g.dfstopo(i,visited,st);
        }
    }
    vector<int>distance(n,INT_MAX);
    g.shortestPath(st,n,distance);
    cout<<endl<<"the shortest path is :"<<endl;
    for(int i =0;i<n;i++){
        cout<<distance[i] <<" ";
    }
        return 0;
}