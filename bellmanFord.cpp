#include <bits/stdc++.h>
#define INF INT_MAX

using namespace std;

typedef pair<int, int> node;
typedef vector<node> graph;

bool checkNCycle(graph Graph[], int V, vector<int> &weight)
{
    for (int u = 0; u < V; ++u)
    {
        int n = Graph[u].size();
        for (int i = 0; i < n; ++i)
        {
            int v = Graph[u][i].first;
            int w = Graph[u][i].second;
            if (weight[u] != INF && weight[v] > weight[u] + w)
                return true;
        }
    }
    return false;
}

vector<int> bellmanFord(graph Graph[], int V)
{
    vector<int> weight(V, INF);
    int src = 0;
    weight[src] = 0;
    for (int k = 0; k < V - 1; ++k)
    {
        for (int u = 0; u < V; ++u)
        {
            int n = Graph[u].size();
            for (int i = 0; i < n; ++i)
            {
                int v = Graph[u][i].first;
                int w = Graph[u][i].second;
                if (weight[u] != INF && weight[v] > weight[u] + w)
                    weight[v] = weight[u] + w;
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
    }

    vector<int> weight = bellmanFord(Graph, V);
    for (int i = 0; i < V; ++i)
        cout << i << " : " << weight[i] << endl;
    if (checkNCycle(Graph, V, weight))
        cout << "Negetive Cycle exists" << endl;
    else
        cout << "Negetive Cycle does not exist" << endl;
    return 0;
}