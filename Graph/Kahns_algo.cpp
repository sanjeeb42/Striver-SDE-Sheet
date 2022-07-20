#include <queue>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Creating adjacency list.
    vector<vector<int>> adj(v);
    for(int i = 0; i < e; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    } 
    // Calculaing indegree of each vertex.
    vector<int> indegree(v);
    for(auto edge : edges) {
        indegree[edge[1]]++;
    }
    // Push all vertices of indegree 0 in queue.
    queue<int> que;
    for(int i = 0; i < v; i++) {
        if(indegree[i] == 0) {
            que.push(i);
        }
    }
    vector<int> result; // It will store topological sort of the given graph.
    // Finding topologial sorting
    while(!que.empty()) {
        int src = que.front();
        que.pop();
        result.push_back(src);
        for(int node : adj[src]) {
            indegree[node]--;
            if(indegree[node] == 0) {
                que.push(node);
            }
        }
    }
    return result;
}
