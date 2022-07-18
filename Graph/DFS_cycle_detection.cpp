/*
    Time Complexity : O(N + M)
    Space Complexity : O(N)

    where 'N' is the number of vertices and
    'M' is the number of edges in the graph.
*/

bool isCycle (int vertex, vector<vector<int>>& graph, vector<bool>& visited, int parent)
{
    visited[vertex] = true;

    for (int adjVertex : graph[vertex])
    {
        if (visited[adjVertex] == false)
        {
            if (isCycle (adjVertex, graph, visited, vertex) == true)
            {
                return true;
            }
        }
        else if (adjVertex != parent)
        {
            return true;
        }
    }

    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<vector<int>> graph(n + 1, vector<int>());

    for (int i = 0; i < m; i++)
    {
        graph[edges[i][1]].push_back(edges[i][0]);
        graph[edges[i][0]].push_back(edges[i][1]);
    }

    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            if (isCycle (i, graph, visited, -1) == true)
            {
                return "Yes";
            }
        }
    }

    return "No";
}
