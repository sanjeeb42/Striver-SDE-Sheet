#include <bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int,vector<int>>&mp,unordered_map<int,bool>&visited,int node,int parent,unordered_map<int,int>&color,int currcolor)
{
    if(visited[node]==true && color[node]!=currcolor)return false;
    if(visited[node]==true && color[node]==currcolor)return true;
    visited[node]=true;
    color[node]=currcolor;
    
    for(auto it:mp[node])
    {
        if(it==parent)
        {
            continue;
        }
        if(dfs(mp,visited,it,node,color,1-currcolor)==false)
        {
            return false;
        }
    }
    
    return true;  
}



int main()
{
	int n, m;
	cin >> n >> m;
    
    
    unordered_map<int,vector<int>>mp;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
        mp[u].push_back(v);
        mp[v].push_back(u);

	}
    
    unordered_map<int,bool>visited;
    unordered_map<int,int>color;
    bool cute=true;
    
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            if(dfs(mp,visited,i,-1,color,0)==false){
                cout<<"NO"<<endl;
                cute=false;
                break;
            }
        }
    }
    if(cute){
        cout<<"YES"<<endl;
    }
    return 0;
}
