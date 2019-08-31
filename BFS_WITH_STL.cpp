// Author: Mohammad Faisal
// Graph Implementation 
/*
	Breath First Search USING STL.
	Dated: 31 - Aug - 2019
	email: mohammad.faisal78612@gmail.com
*/
#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;
int main()
{
	int no_of_vertices, no_of_edges;
	cin >> no_of_vertices >> no_of_edges;
	map<int, vector<int>> graph;
	for (int i = 0; i < no_of_edges; ++i)
	{
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<bool> visited(no_of_vertices, false);
	queue<int> myqueue;
	myqueue.push(1);
	visited[1] = true;
	while(!myqueue.empty())
	{
		int this_vertex = myqueue.front();
		cout << this_vertex << " -> ";
		myqueue.pop();
		for (int connected: graph[this_vertex])
		{
			if (!visited[connected])
			{
				myqueue.push(connected);
				visited[connected] = true;
			}
		}
	}
	cout << endl;
	return 0;
}
