#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



///======================DSU=======================
// maximum 1000 nodes possible
int n; // node number;
int parent[1000]; // to track parents
int _rank[1000]; // to track rank


void init_set()
{
    for(int i=0;i<=n;i++)
    {
        parent[i]=i; // initially every node is it's own parent
        _rank[i]=0;
    }

}

int _find(int u) // find the root
{
    if(parent[u]==u)
        return u;
    else return _find(parent[u]);
}

bool _union(int u,int v) // return true if the union happened
{
    int root_u=_find(u);
    int root_v=_find(v);
    if(root_u!=root_v)
    {
        /// rank updates and logical part fully depends on the problem
        if(_rank[root_u]>_rank[root_v])
        {
            parent[root_v]=root_u;
            //_rank[root_u]+=_rank[root_v] if you do rank by size.you can use any other logic
            // rank update if necessary

        }
        else if(_rank[root_u]<_rank[root_v])
        {
            parent[root_u]=root_v;
            //_rank[root_v]+=_rank[root_u] if you do rank by size.you can use any other logic
            // rank update if necessary

        }
        else // tie
        {
            parent[root_v]=root_u; // we randomly chose root_u as parent
            _rank[root_u]++;

        }
        return true;
    }
    return false;

}



///=======================kruskal===============================

struct edge{
    int u; // start node
    int v; // end node
    int weight;
};
vector<edge>edges;

// custom sort for edges

bool compare(struct edge &a,struct edge &b) /// & to maintain same memory
{

    if(a.weight>=b.weight)
    {
        return false; // because I want to swap
    }
    else
        return true;

}


int main()
{
    // input==============================
    int m; // no of edges
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        struct edge e;
        cin>>e.u>>e.v>>e.weight;
        edges.push_back(e);
    }

    sort(edges.begin(),edges.end(),compare);
    // choose edges one by one=========================
    init_set();
    int cost=0;
    for(int i=0;i<m;i++)
    {
        if(_union(edges[i].u,edges[i].v))
        {
            cost+=edges[i].weight;
        }

    }
    cout<<cost<<endl;



}








