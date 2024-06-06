class DSU {
    public:
    vector<int>parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n);
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
           	//If rank is same
            parent[v] = u;
            rank[u]++;
        }

       	//If rank different--> Connect Lower rank tree to higher tree

        else
        {
            if (rank[u] > rank[v])
            {
                parent[v] = u;
            }
            else parent[u] = v;
        }
    }
};
