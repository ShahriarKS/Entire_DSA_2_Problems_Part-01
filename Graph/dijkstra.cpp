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

/// if a node is in dijkstra, visited should be true
bool visited[1000];

/// UPDATE-1 (change wrt prims)
int distance_map[1000]; // distance_map[node]=distance from source to node

int parent[1000]; // parent[u] is the parent of node u


// returns the distance from source u to destination v
int dijkstra(int u, int v)
{
    ///min heap declare: priority_queue<type,vector<type>,greater<type>>
    /// pair saves <weight/key, node>
    
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq; 
    //priority_queue<pair<int,int>>pq; /// for max-ST=============================

    pq.push({0,u}); // the source have key 0;
    distance_map[u]=0;
    while(!pq.empty())
    {
        //for each pair,first number is the key,second number is the node
        pair<int,int> current=pq.top();

        // step-1: POP
        pq.pop();

        // step-2: MAKE VISITED
        if(visited[current.second]==true) // already inside the dijkstra
            continue;

        // not inside dijkstra
        visited[current.second]=true;

        int current_distance=current.first; // distance from source to current node

        // step-3: UPDATE DISTANCES
        for(int i=0;i<adj[current.second].size();i++)
        {
            int neighbour=adj[current.second][i].first;
            int weight= adj[current.second][i].second;
            if(visited[neighbour]==false) // still not inside dijkstra
            {
                /// UPDATE-2 (change wrt prims)
                if(current_distance+weight < distance_map[neighbour]) /// d[u] + w(u,v) < d[v]
                {
                    distance_map[neighbour]=current_distance+weight; // distance map update
                    parent[neighbour]=current.second; // update parent
                    pq.push({distance_map[neighbour],neighbour}); // push into the heap
                }
                
            }
        }

    }

    return distance_map[v]; // distance from source to destination

}



// print the path from destination to source
void print_path(int node)
{
    if(parent[node]==node)
    {
        return;
    }
    cout<< node<< " ";
    print_path(parent[node]);
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

        // graph directed
        // adj[u].push_back({v,weight});
    }

    /// UPDATE-1 (change wrt prims)
    for(int i=0;i<=n;i++)
    {
        distance_map[i]=100000000; // infinity
        parent[i]=i; // parent of each node is itself
    }
    int ending_node;
    cin>>ending_node; // destination node

    // starting node is 1, destination node is ending_node
    cout<<dijkstra(1,ending_node)<<endl;
    print_path(ending_node); // print path from destination to source

}

