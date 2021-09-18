#include <bits/stdc++.h>

using namespace std;

void topologicalSortUtil(vector<int> Graph[], int V, bool Visited[], stack<int> &Stack, int i)
{
    Visited[i] = true;
    int n = Graph[i].size();
    for (int j = 0; j < n; ++j)
        if (!Visited[Graph[i][j]])
            topologicalSortUtil(Graph, V, Visited, Stack, Graph[i][j]);
    Stack.push(i);
}

void topologicalSort(vector<int> Graph[], int V)
{
    bool Visited[V] = {false};
    stack<int> Stack;
    for (int i = 0; i < V; ++i)
        if (!Visited[i])
            topologicalSortUtil(Graph, V, Visited, Stack, i);

    while (!Stack.empty())
    {
        cout << Stack.top() << " ";
        Stack.pop();
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
    vector<int> Graph[V];
    for (int i = 0; i < E; ++i)
    {
        int s, d;
        cin >> s >> d;
        Graph[s].push_back(d);
    }
    topologicalSort(Graph, V);
    return 0;
}