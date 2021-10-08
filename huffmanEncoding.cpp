#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
    char s;
    int freq;
    node *lnode, *rnode;
} Node;

struct comparator
{
    bool operator()(Node *x, Node *y)
    {
        return x->freq > y->freq;
    }
};

void printTree(Node *root, string str = "")
{
    if (root == NULL)
        return;

    if (root->s != '$')
        cout << root->s << " - " << str << endl;
    printTree(root->rnode, str + "1");
    printTree(root->lnode, str + "0");
}

void huffman(vector<pair<char, int>> a)
{
    priority_queue<Node *, vector<Node *>, comparator> min_heap;
    for (auto i : a)
    {
        Node *x = (Node *)malloc(sizeof(Node));
        x->s = i.first;
        x->freq = i.second;
        x->lnode = x->rnode = NULL;
        min_heap.push(x);
    }
    while (min_heap.size() > 1)
    {
        Node *x = min_heap.top();
        min_heap.pop();
        Node *y = min_heap.top();
        min_heap.pop();
        Node *n = (Node *)malloc(sizeof(Node));
        n->s = '$';
        n->freq = x->freq + y->freq;
        n->lnode = x;
        n->rnode = y;
        min_heap.push(n);
    }
    printTree(min_heap.top());
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    vector<pair<char, int>> a;
    for (int i = 0; i < n; ++i)
    {
        char c;
        int x;
        cin >> c >> x;
        a.push_back(make_pair(c, x));
    }
    huffman(a);
    return 0;
}