// Author: Mohammad Faisal
// Implementation Of Depth First Search using STL.
#include<bits/stdc++.h>
using namespace std;
void smallDFS(map<int, vector<int> > &graph, int sv, vector<bool> &visited)
{
	visited[sv] = true;
	cout<<sv<<"------>";
	for(int conn: graph[sv])
	{
		if(!visited[conn])
		{
			smallDFS(graph,conn,visited);
		}
	}
	
}
void DFS(map<int, vector<int> > &graph, int n)
{
	vector<bool> visited(n,false);
	for(int i=1; i<=n;i++)
		if(!visited[i])
			smallDFS(graph,i,visited);
}
int main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	map<int ,vector<int> > graph;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(graph,n);
	cout<<" END";
	return 0;
	// vector<bool> visited(n,false);
}
