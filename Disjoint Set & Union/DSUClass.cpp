// DSU class from Sanjeeb - Template github -https://github.com/sanjeeb42/Striver-SDE-Sheet/blob/main/Disjoint%20Set%20%26%20Union/DSUClass.cpp
class DSU {
    public:
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n+1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        rank.resize(n+1, 0);
    }

    int find_parent(int u) {
        if (parent[u] == u)
            return u;

        return parent[u]=find_parent(parent[u]);
    }

    void union_nodes(int u, int v) {
        int p1 = find_parent(u), p2 = find_parent(v);
        if(p1==p2)return;
        int rank1 = rank[p1], rank2 = rank[p2];

        if (rank1 == rank2) {
            rank[p1] += 1;
            parent[p2] = p1;
        } else if (rank1 > rank2) {
            parent[p2] = p1;
        } else
            parent[p1] = p2;
    }
};
