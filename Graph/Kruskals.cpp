#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &edges)
{
    // Write your code here.
    //Form the adjacency Matrix First
    
    unordered_map<int,list<pair<int,int>>>mp;
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first.first;
        int v=edges[i].first.second;
        int w=edges[i].second;
        
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
    }
    
    //Task2 :- Initialisation
    vector<int>key(n+1,INT_MAX);
    vector<bool>mst(n+1,false);
    vector<int>parent(n+1,-1);
    
    key[1]=0;
    parent[1]=-1;
    
    //Now Forming the Complex Code
    for(int i=1;i<n;i++)
    {
        
        //Find the min Key
        int u;
        int mini=INT_MAX;
        for(int v=1;v<=n;v++)
        {
            if(mst[v]==false && key[v]<mini)
            {
                mini=key[v];
                u=v;
            }
        }
        
        mst[u]=true;
        //Now For all the connect edges perform the required operations
        
        for(auto it:mp[u])
        {
            //Initialise 
            int next=it.first;
            int cost=it.second;
            
            //check conditions
            if(mst[next]==false && key[next]>cost)
            {
                parent[next]=u;
                key[next]=cost;
            }
        }
    }
    
    //Now Push it into final ans;
    
    vector<pair<pair<int, int>, int>>fans;
    
    for(int i=2;i<=n;i++)
    {
        fans.push_back({{parent[i],i},key[i]});
    }
    
    return fans;
    
    
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  
  return 0;
}
