// Author: Mohammad Faisal
// Email: mohammad.faisal78612@gmail.com
/*
    You have been given a Tree consisting of N nodes. A tree is a fully-connected graph consisting of N nodes and N−1
 edges. The nodes in this tree are indexed from 1 to N. Consider node indexed 1 to be the root node of this tree. The root node lies at level one in the tree. 
 You shall be given the tree and a single integer x . You need to find out the number of nodes lying on level x. 
*/
// https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/

#include<bits/stdc++.h>  
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int e = n-1;
    map<int,vector<int> > graph;
    for(int i=0;i<e;i++)
    {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int x;
    cin >> x;
    int * level = new int[n+1];
    level[1] = 1;
    vector<bool> visited(n,false);
    queue<int> pending;
    pending.push(1);
    visited[1] = true;
    while(!pending.empty())
    {
        int curr = pending.front();
        pending.pop();

        // cout<<curr<<"<-->";

        for(int conn: graph[curr])
        {

            if(!visited[conn])
            {
                level[conn] = level[curr]+1;
                pending.push(conn);
                visited[conn] = true;
            }

        }

    }
    int k=0;
    for(int i=1;i<=n;i++)
        if(level[i]==x)
            k++;
    cout<<k<<endl;
    delete[] level;
    return 0;
}
