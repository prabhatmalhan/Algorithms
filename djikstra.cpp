//Directed Graph Djikstra

#include <bits/stdc++.h>

#define INF INT_MAX

using namespace std;

typedef pair<int, int> node;
typedef vector<node> graph;

vector<int> Djikstra(graph Graph[], int V, int src)
{
    vector<int> weight(V, INF);
    vector<bool> visited(V, false);
    priority_queue<node, graph, greater<node>> min_heap;
    weight[src] = 0;
    min_heap.push(make_pair(weight[src], src));
    while (!min_heap.empty())
    {
        int u = min_heap.top().second;
        min_heap.pop();
        visited[u] = true;
        int n = Graph[u].size();

        for (int i = 0; i < n; ++i)
        {
            int v = Graph[u][i].first;
            int w = Graph[u][i].second;

            if (weight[v] > weight[u] + w)
            {
                weight[v] = weight[u] + w;
                if (!visited[v])
                    min_heap.push(make_pair(weight[v], v));
            }
        }
    }
    return weight;
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
        // Graph[d].push_back(make_pair(s, w)); // uncomment to make graph undirected
    }
    int src;
    cin >> src;
    vector<int> weights = Djikstra(Graph, V, src);
    int n = weights.size();
    for (int i = 0; i < n; ++i)
        cout << i << " " << weights[i] << endl;
    return 0;
}