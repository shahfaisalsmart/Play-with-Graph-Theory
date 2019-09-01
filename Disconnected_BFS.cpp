// Author: Mohammad Faisal
/*  
    DISCONNECT GRAPH BFS TRAVERSAL USING STL 
    EMAIL: mohammad.faisal78612@gmail.com
    Dated: 01-09-2019
 */
#include<bits/stdc++.h>
using namespace std;
void chotaBFS(map<int,vector<int> > &graph, vector<bool> &visited, int node)
{
	queue<int>pending;
	pending.push(node);
	visited[node] = true;
	while(!pending.empty())
	{
		int curr = pending.front();
		pending.pop();
		cout<<curr<<"---";
		for(int link: graph[curr])
		{
			if(!visited[link])
			{
				pending.push(link);
				visited[link] = true;
			}
		}
	}
	cout<<"--END"<<endl;
	// pending.clear();
}
void Disconnect_BFS(map<int, vector<int> > graph, int n)
{
	vector<bool> visited(n,false);
	for(int j=1;j<=n;j++)
		if(visited[j]==false)
			chotaBFS(graph,visited,j);
			
	visited.clear();
}
int main()
{
	int n,e;
	cin >> n >> e;
	map<int,vector<int> > graph;
	for(int i=0;i<e;i++)
	{
		int a , b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	Disconnect_BFS(graph, n);
	graph.clear();
	return 0;
}
