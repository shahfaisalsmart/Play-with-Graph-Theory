// Author:: Mohammad Faisal
// Graph Theory SHORTEST PATH
// BEGINNING WITH THE NAME OF GOD

#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

class graph{
    int ver;
    vector <pair<int,int> > *adj;
    
    public:
        graph(int ver)
        {
            this->ver = ver;
            adj = new vector<pair<int,int> >[ver];
        }
        void edges(int u,int v,int w)
        {
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        
        void shortest(int val);
};
void graph::shortest(int so)
{
    set< pair<int,int> > node;
    vector<int> dis(ver,INF);
 
    node.insert(make_pair(0,so));
    dis[so] = 0;
    
    while(!node.empty())
    {
        pair<int,int> temp = *(node.begin());
        node.erase(node.begin());
        
        int cv = temp.second;
        
        for(vector<pair<int,int> >::iterator it=adj[cv].begin();it!=adj[cv].end();it++)
        {
            int a = (*it).first;
            int b = (*it).second;
            
            if(dis[a] > dis[cv]+b)
            {
                
                if(dis[a]!=INF){
                    node.erase(node.find(make_pair(dis[a],a)));}
                
                dis[a] = dis[cv]+b;
                node.insert(make_pair(dis[a],a));
            }
            
        }
    }
    cout<<"Dijakstra successfully solved"<<endl;
    for(int i=0; i<ver;i++)
    {
        cout<<i<<" "<<dis[i]<<endl;
    }
}
int main()
{
    int n,e;
    cin >> n >> e;
    
    graph g(n);
    
    for(int i=0;i<e;i++)
    {
        int w;
        int s,f;
        cin >> s >> f >> w;
        g.edges(s,f,w);
    }
    g.shortest(0);
    return 0;
}
