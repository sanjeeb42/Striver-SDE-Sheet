int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Write your code here.

    // Creating the Required mapping
    // unordered_map<int, vector<pair<int, int>>> mp;
    // for (int i = 0; i < edges.size(); i++)
    // {
    //     int u = edges[i][0];
    //     int v = edges[i][1];
    //     int w = edges[i][2];
    //     mp[u].push_back({v, w});
    // }

    // Now going for the algorithm

    vector<long long> distance(n + 1, 1e9);
    distance[src] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int weight = it[2];
               
                if (distance[u]!=1e9 && distance[u] + weight< distance[v])
                {
                    distance[v] = distance[u] + weight;
                }
            }
        
    }

    bool negcycle = false;

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int weight = it[2];
        if (distance[u]!=1e9 && distance[u] + weight< distance[v])   
        {
           negcycle=true;
           break;
         }
    }

    if (negcycle)
    {
        return 1e9;
    }

    return distance[dest];
}
