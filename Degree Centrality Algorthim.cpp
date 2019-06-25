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
	
	//*****************************Degree_centrality**********************************//
	for (int i = 0; i < adj_list.size(); i++)
	{
		cout<<adj_list[i].size()<<endl;
	}
}
