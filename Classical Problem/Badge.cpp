// Author: Mohammad Faisal
// Email: mohammad.faisal78612@gmail.com
// Codeforces: https://codeforces.com/problemset/problem/1020/B

#include<bits/stdc++.h>
using namespace std;
bool visited[1001];
int arr[10001];
int dfs(int s)
{
	visited[s] = true;
	if(visited[arr[s]])
		return arr[s];
	return dfs(arr[s]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	// int * arr = new int[n+1];
	for(int i=1;i<=n;i++)
	{
		cin >> arr[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			visited[j] = false;
		
		cout<<dfs(i)<<" ";
	}
	return 0;
}
