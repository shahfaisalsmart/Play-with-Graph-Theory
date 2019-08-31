// Author: Mohammad Faisal
// Graph Implementation 
/*
	Breath First Search
	Dated: 31 - Aug - 2019
	email: mohammad.faisal78612@gmail.com
*/
#include<iostream>
#include<queue>
using namespace std;
void Print_BFS(int** edges, int n, int sv)
{
	queue<int> pv;
	bool * visited = new bool[n];
	for(int i=0;i<n;i++)
		visited[i] = false;

	pv.push(sv);
	visited[sv] = true;

	while(!pv.empty())
	{
		int curr_v = pv.front();
		pv.pop();

		cout<<curr_v<<endl;

		for(int i=0;i<n;i++)
		{
			if(i==curr_v)
			{
				continue;
			}
			if(edges[curr_v][i]==1 && !visited[i])
			{
				pv.push(i);
				visited[i] =true;
			}
		}
	}
	delete[] visited;

}
int main()
{
	int n,e;
	cin >> n >> e;
	int ** edges = new int*[n];
	for(int i=0;i<n;i++)
	{
		edges[i] = new int[n];

		for(int j=0;j<n;j++)
		{
			edges[i][j]=0;
		}
	}
	for(int i=0;i<e;i++)
	{
		int f,s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;

	}
	// bool * visited = new bool[n];
	// for(int i=0;i<n;i++)
	// 	visited[i] = false;

	Print_BFS(edges,n,0);
	// delete[] visited;
	for(int i=0;i<n;i++)
	{
		delete[] edges[i];
	}
	delete[] edges;
}
