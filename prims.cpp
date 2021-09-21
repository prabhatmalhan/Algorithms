#include <bits/stdc++.h>

#define INF INT_MAX
#define NIL -1

using namespace std;

typedef vector<pair<int, int>> graph;

vector<int> prims(graph Graph[], int V)
{
    priority_queue<pair<int, int>, graph, greater<pair<int, int>>> min_heap;
    vector<int> key(V, INF);
    vector<int> parent(V, NIL);
    vector<bool> visited(V, false);
    int src = 0;
    key[src] = 0;
    min_heap.push(make_pair(key[src], src));
    while (!min_heap.empty())
    {
        int u = min_heap.top().second;
        min_heap.pop();
        if (!visited[u])
        {
            visited[u] = true;
            int n = Graph[u].size();
            for (int i = 0; i < n; ++i)
            {
                int v = Graph[u][i].first;
                int w = Graph[u][i].second;
                if (!visited[v] && key[v] > w)
                {
                    key[v] = w;
                    min_heap.push(make_pair(key[v], v));
                    parent[v] = u;
                }
            }
        }
    }
    return parent;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int V, E;
    cin >> V >> E;
    graph Graph[V];
    for (int i = 0; i < E; ++i)
    {
        int s, d, w;
        cin >> s >> d >> w;
        Graph[s].push_back(make_pair(d, w));
        Graph[d].push_back(make_pair(s, w));
    }
    vector<int> parent = prims(Graph, V);
    for (int i = 0; i < V; ++i)
        cout << i << " - " << parent[i] << endl;
    return 0;
}