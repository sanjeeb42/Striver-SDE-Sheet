vector <int> dijkstra(int v, vector<vector<int>> adj[], int s)
    {
        // Code here
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<v;i++){
            int u=i;
            auto edges=adj[i];//vector of vector
            for(auto it:edges){
                int v=it[0], weight=it[1];
                mp[u].push_back({v,weight});
            }
        }
        
    
        //Formed the matrix successfully
        //Now time to try solving it using Dijkstra Algorithm
        
        //I am trying to find peace in chaos
        //In Dijkstra Algo we use a priority queue type thing to know which is the minimum 
        
        vector<int>distance(v,INT_MAX);
        distance[s]=0;
        
        set<pair<int,int>>st; // Distance and node 
        st.insert({0,s});
        
        while(st.size()>0){
            auto front=*(st.begin());
            st.erase(st.begin());
            
            int curr_dist=front.first,node=front.second;
            
            for(auto it: mp[node]){
                
                //Perforn Relaxation
                int next_node=it.first, weight=it.second; // We have node & weight
                
                int new_dist=curr_dist+weight;
                if(distance[next_node]>new_dist){
                    st.erase({distance[next_node],next_node});
                    distance[next_node]=new_dist;
                    st.insert({new_dist,next_node});
                }
            }
        }
        
        
        return distance;
        
    }
