// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL
/*  
    Req: Graphs, ShortestPath;
    Codeforces: Christmas Trees
    Link: https://codeforces.com/contest/1283/problem/D
 */
#include<bits/stdc++.h>
#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<chrono>
#include<random>
#define ll long long

using namespace std;
//using chrono;
//mt19937 rnd(time(NULL));
int main()
{
//    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n,m;
    cin >> n >> m;
    queue<ll> pos;
    map<ll,ll> mp;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin >> x;
        mp[x] = 0;
        pos.push(x);
    }
    ll res = 0;
    vector<ll> persons;
    while(!pos.empty())
    {
        ll ele = pos.front();
        pos.pop();
        if(persons.size()==m) break;
        
        if(mp[ele]!=0)
        {
            res+= mp[ele];
            persons.push_back(ele);
        }
        if(!mp.count(ele-1))
        {
            mp[ele-1] = mp[ele] +1;
            pos.push(ele-1);
        }
        if(!mp.count(ele+1))
        {
            mp[ele+1] = mp[ele] +1;
            pos.push(ele+1);
        }
    }
    cout<<res<<endl;

    auto rng = std::default_random_engine {};
    shuffle(persons.begin(),persons.end(),rng);
    for(auto &k: persons)
        cout<<k<<" ";
    return 0;
}
