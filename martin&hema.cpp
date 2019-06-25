#include <iostream>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
using namespace std;
#define INF 1000000

double print_path ( int src , int des ,int scored_node, vector<vector<int>>p,int count ){
	double num,den=0;	double score=0;	double num1=0;
  vector<int> counter(count,0);  stack<int> pathnodes ;
//......new.........//
  if(p[des].size()==0) return 0;
//......start_counter......//
int counterrrr=0;
//......number_of_pathes......//
den=p[des].size();
//......start_extracting of pathes.....//
while(counterrrr<p[des].size()){
	int node = des ;
pathnodes . push ( node ) ;
//......till_finding....source........//
 while ( p [node][0]!= node ){
	node= p[node][counter[node]] ;
	//.........increase_iteration_of_counters...........//
	counter[node]=(( counter[node]+1 )% ( p[node].size() ) );
	pathnodes.push(node);
      }
counter[des]=((counter[des]+1)%(p[des].size()));
if(scored_node==src||scored_node==des){num=-1;}
else{	num=0;}
while ( !pathnodes.empty()) {
	if(pathnodes.top()==scored_node){num++;}
	//cout<<pathnodes.top()<<",";
pathnodes.pop();
}
//cout<<endl;
num1+=num;
counterrrr++;
}
score=(num1/den);
return score;
}
vector<int> Dijkstra(int src,vector<vector<pair<int,int>>> adj_list,vector<vector<int>> &parent){
	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> nodes_q;
	int n=adj_list.size();
	vector<int>d(n,INF);
	vector<vector<int>>P(n);
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
		if ((d[cur_node]!=INF)&&cur_dis!=d[cur_node]) 
			continue;
		d[cur_node]=cur_dis;
		//.................//
		P[cur_node].push_back(cur_prev_node);
		//.................//
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
	parent=P;
	return d;
}
int main(){
	int direct=0;
	int vertices=0;
	int num_edges=0;
	vector<int> distance;
	vector<vector<int>> parent;
	int counter;
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
	for(int x=0 ;x<vertices;x++)
	{
	double score =0;

	for(int i=0 ;i<vertices;i++){
		distance=Dijkstra(i,adj_list,parent);
		for(int j=i+1;j<vertices;j++)
		{
	    score+=print_path(i ,j,x, parent,vertices);		
		}
	}	
	cout<<score<<endl;
	}
	while (true)
	{

	}	
}
