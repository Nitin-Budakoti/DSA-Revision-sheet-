class DisjointSet {
vector<int>rank,size,parent;
public:
    DisjointSet(int n) {
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1,0);
        for(int i =0 ;i<n+1;i++){
            parent[i] =i;
        }
    }

    bool find(int u, int v) {
     int pu = findParent(parent,u);
     int pv = findParent(parent,v);
     if(pu==pv) return true;
     return false;
    }
    int findParent(vector<int>parent,int x){
        if(parent[x]==x)return x;
        return parent[x] = findParent(parent,parent[x]);
    }

    void unionByRank(int u, int v) {
     int pu = findParent(parent,u);
     int pv= findParent(parent,v);
     int pur = rank[pu];
     int pvr = rank[pv];
     if(pur<pvr){
        parent[pu] = pv;
     }
     else if(pur>pvr){
        parent[pv] = pu;
     }
     else{
        parent[pv]=pu;
        rank[pu]++;
     }
    }


    void unionBySize(int u, int v) {
       int pu = findParent(parent,u);
       int pv= findParent(parent,v);
        if(size[pu]<size[pv]){
            parent[pu] = pv;
            size[pv]+=size[pv];
        }
        else{
            parent[pv] =pu;
            size[pu]+= size[pv];
        }
    }
};
