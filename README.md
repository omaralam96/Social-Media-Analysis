# Degree centrality algorithm

The degree centrality for a node is simply its **degree** *"Node's degree is simply a count of edges it has."*.

### Steps of Implementation :
&nbsp; &nbsp; 1. create a graph in shape of adjacent list as follow:
```C++
   vector<vector<pair<int,int>>> adj_list(vertices,vector<pair<int,int>>());
```
&nbsp; &nbsp;  2. Fill adjancey list with nodes and edges .
```C++
   for (int i = 0; i < num_edges; i++)
	{
		cin>>a>>b>>c;
		pair<int,int>p1(b,c); 
		pair<int,int>p2(a,c); 
		adj_list[a].push_back(p1);
		adj_list[b].push_back(p2);
	}
```
&nbsp; &nbsp;  3. Apply Degree centrality algorithm by knowing number of edges of each node.
```C++
   for (int i = 0; i < adj_list.size(); i++)
	{
		cout<<adj_list[i].size()<<endl;
	}
```

### Used Tools & Libraries :
#### A.Tools :
- Visual studio

#### B.Libraries :
- iostream &nbsp; &nbsp; " for input / output purpose ".
- vector&nbsp; &nbsp; &nbsp; &nbsp; &nbsp;" for building up graph ".
- stdlib &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;  &nbsp;"in order to use pair<> in graph"