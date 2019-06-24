# Closeness centrality algorithm
Closeness centrality indicates how close a node is to all other nodes in the network. It is calculated as the average of the shortest path length from the node to every other node in
the network.
> For a node x and a graph of N connected nodes, The centrality C(x) is defined as:
> C(x)= (N-1)/∑ d(y,x)
### Steps :
1. Fill adjancey list with nodes and edges .
2. Implement Dijkstra's algorithm to get shortest distance from src "x" to all connected nodes .
```C++
vector<int> Dijkstra(int src,vector<vector<pair<int,int>>> adj_list);
```
3. Apply Closeness centrality algorithm by summing distances from src "x" to all connected nodes "y", then dividing
**(number of connected nodes -1 )/sum of distances**
```C++
double closeness_centrality(int src,vector<vector<pair<int,int>>> adj_list);
```

> Used tools: Visual studio

> Used libraries:
  1. STL library :
    - Vector container
    - priority_queue: to get shortest distance from source
  2. iostream
