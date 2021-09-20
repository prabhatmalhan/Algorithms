#include <bits/stdc++.h>

using namespace std;

int find(int u, int parent[])
{
    if (parent[u] < 0)
        return u;
    return find(parent[u], parent);
}

void unionByWeight(int u, int v, int parent[])
{
    int pu = find(u, parent), pv = find(v, parent);
    if (pu != pv)
    {
        if (parent[pu] > parent[pv])
        {
            parent[pv] += parent[pu];
            parent[pu] = pv;
        }
        else
        {
            parent[pu] += parent[pv];
            parent[pv] = pu;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int V, E;
    cin >> V >> E;
    int parent[V];
    for (int i = 0; i < V; ++i)
        parent[i] = -1;
    for (int i = 0; i < E; ++i)
    {
        int s, d;
        cin >> s >> d;
        unionByWeight(s, d, parent);
    }
    for (int i = 0; i < V; ++i)
        cout << i << " - " << parent[i] << endl;
    return 0;
}