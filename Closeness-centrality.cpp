#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define INF 1000000
vector<int> Dijkstra(int src,vector<vector<pair<int,int>>> adj_list){
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> nodes_q;
	int n=adj_list.size();
	vector<int>d(n,INF);
	vector<int>P(n,-1);
	pair<int,int>p1(src,src);
	pair<int,pair<int,int>>p2(0,p1);
	nodes_q.push(p2);
	while (!nodes_q.empty())
	{
		pair<int,pair<int,int>>p=nodes_q.top();
		nodes_q.pop();
		int cur_node=p.second.first;
		int cur_prev_node=p.second.second;
		int cur_dis=p.first;
		if (d[cur_node]!=INF)
			continue;
		d[cur_node]=cur_dis;
		P[cur_node]=cur_prev_node;
		for (int i = 0; i < adj_list[cur_node].size(); i++)
		{
			int next_node=adj_list[cur_node][i].first;
			int weight=adj_list[cur_node][i].second;
			if (d[next_node]!=INF)
			{
				continue;
			}
				pair<int,int>p3(next_node,cur_node);
				pair<int,pair<int,int>>p4(cur_dis+weight,p3);
				nodes_q.push(p4);
		}
	}
	return d;
}
double closeness_centrality(int src,vector<vector<pair<int,int>>> adj_list){
	vector<int> dijk=Dijkstra(src,adj_list);
	int sum_dist=0;
	int N=0;
	for (int i = 0; i < dijk.size(); i++)
	{
		if (dijk[i]!=INF)
		{
			N++;
			sum_dist+= dijk[i];
		}
	}
	double centrality=(N-1)/(double)sum_dist;
	return centrality;
}

int main(){
	int direct=0;
	int vertices=0;
	int num_edges=0;
	cin>>vertices;
	cin>>num_edges;
	vector<vector<pair<int,int>>> adj_list(vertices,vector<pair<int,int>>());
	int a,b,c;
	for (int i = 0; i < num_edges; i++)
	{
		cin>>a>>b>>c;
		pair<int,int>p1(b,c); 
		pair<int,int>p2(a,c); 
		adj_list[a].push_back(p1);
		adj_list[b].push_back(p2);
	}
	
	///////////////closeness_centrality////////////
	for (int i = 0; i < adj_list.size(); i++)
	{
		cout<<closeness_centrality(i,adj_list)<<endl;
	}
}
