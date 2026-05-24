#include<iostream>
#include<vector>
#include<queue>
using namespace std;


/// suppose total 1000 nodes.
/// adj vector is the adjacency list. every index has a vector for each node

// adj[u] means node u's neighbours' list
// if neighbours are (u,w,5),(u,x,6),(u,y,7)
// then adj[u]'s pairs are [ <w,5>,<x,6>,<y,7> ]
vector<pair<int,int>>adj[1000];

/// if a node is in MST, visited should be true
bool visited[1000];

int prims(int u)
{
    ///min heap declare: priority_queue<type,vector<type>,greater<type>>
    /// pair saves <weight/key, node>
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,u}); // the source have key 0;
    int cost=0;
    while(!pq.empty())
    {
        //for each pair,first number is the key,second number is the node
        pair<int,int> current=pq.top();
        pq.pop();
        if(visited[current.second]==true) // already inside the MST
            continue;

        // not inside MST
        visited[current.second]=true;
        cost+=current.first;
        for(int i=0;i<adj[current.second].size();i++)
        {
            int neighbour=adj[current.second][i].first;
            int weight= adj[current.second][i].second;
            if(visited[neighbour]==false) // still not inside MST
            {
                pq.push({weight,neighbour});
            }
        }

    }

    return cost;

}

int main()
{
    int n,m;
    cin>>n>>m; // n= nodes, m=edges

    for(int i=0;i<m;i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        // graph undirected
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }
    // starting node is 1
    cout<<prims(1)<<endl;

}


