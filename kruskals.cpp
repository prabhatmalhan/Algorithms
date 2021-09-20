#include <bits/stdc++.h>

using namespace std;

typedef vector<pair<int, pair<int, int>>> graph;

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

graph Kruskals(graph Graph, int V)
{
    graph result;
    int parent[V];

    for (int i = 0; i < V; ++i)
        parent[i] = -1;

    sort(Graph.begin(), Graph.end());

    int E = Graph.size();

    for (int i = 0; i < E; ++i)
    {
        int w = Graph[i].first;
        int s = Graph[i].second.first;
        int d = Graph[i].second.second;
        if (find(s, parent) != find(d, parent))
        {
            unionByWeight(s, d, parent);
            result.push_back(Graph[i]);
        }
    }
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    graph Graph;
    int V, E;
    cin >> V >> E;
    for (int i = 0; i < E; ++i)
    {
        int s, d, w;
        cin >> s >> d >> w;
        Graph.push_back(make_pair(w, make_pair(s, d)));
    }
    graph result = Kruskals(Graph, V);

    int ER = result.size();
    int s = 0;

    for (int i = 0; i < ER; ++i)
    {
        s += result[i].first;
        cout << result[i].second.first << " " << result[i].second.second << endl;
    }

    cout << "Weight : " << s << endl;

    return 0;
}