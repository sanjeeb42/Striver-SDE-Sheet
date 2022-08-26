class Solution
{
    public:
   int parent[200];
    int rank[200];

    void initialise(int n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    int findparent(int node)
    {
        if (parent[node] == node) return node;
        return parent[node] = findparent(parent[node]);
    }
    void unionset(int u, int v)
    {

        u = findparent(u);
        v = findparent(v);


        if (rank[u] == rank[v])
        {
           	//If ran is same
            parent[v] = u;
            rank[u]++;
        }

       	//If rank differen--> Connect Lower rank tree to higher tree

        else
        {

            if (rank[u] > rank[v])
            {
                parent[v] = u;
            }
            else parent[u] = v;
        }
    }

    int findCircleNum(vector<vector < int>> &graph)
    {

       // Initialise the graph
       
        int n = graph.size();
        
       	//Do Union Find

       	//Step 1: Initialise
        initialise(n);

       	//step 2: Do union of all available edges
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

               	//Do Union
                if(i!=j && graph[i][j]==1){
                    unionset(i,j);
                }

            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i)ans++;
        }
        
        return ans;
    }
};
