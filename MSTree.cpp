#include "MSTree.h"

typedef pair<int, int> edge;
void MSTree::primMST( vector<vector<int>>& graph )
{
    priority_queue< edge, vector <edge> , greater<edge> > pq;

    int src = 0;

    vector<int> key(graph.size(), INT_MAX);

    vector<int> parent(graph.size(), -1);

    vector<bool> inMST(graph.size(), false);

    pq.push(make_pair(0, src));
    key[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if (inMST[u] == true)
            continue;

        inMST[u] = true;

        for (int i = 0; i != graph.size(); ++i)
        {
            int weight = graph[u][i];

            if (inMST[i] == false && key[i] > weight)
            {
                key[i] = weight;
                pq.push(make_pair(key[i], i));
                parent[i] = u;
            }
        }
    }
}