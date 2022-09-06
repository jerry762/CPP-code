#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <stack>

using namespace std;
#define INF 0x3f3f3f3f

typedef pair<int, int> iPair;

void addEdge(vector<pair<int, int>> adj[], int u,
             int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

ostream &operator<<(ostream &out, const iPair &pair)
{
    out << "(" << pair.first << "," << pair.second << ")";
    return out;
}

void shortestPath(vector<iPair> adj[], int V, int src, int target)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;

    vector<int> dist(V, INF);
    vector<bool> visited(V, false);

    array<int, 9> M;
    M.at(src) = -1;

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {

        int u = pq.top().second;
        pq.pop();
        if (visited[u])
        {
            continue;
        }
        visited[u] = true;

        for (auto x : adj[u])
        {

            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                M[v] = u;
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
    cout << endl;

    // cout << "Target " << target << ": " << dist[target] << endl;

    cout << endl;
    for (int i = 0; i < V; i++)
    {
        int index = i;
        stack<int> sto;

        while (index >= 0)
        {
            sto.push(index);
            index = M[index];
        }

        cout << src << " ~ " << i << ": ";
        while (!sto.empty())
        {
            cout << sto.top() << " ";
            sto.pop();
        }
        cout << endl;
    }
}

int main()
{
    int V = 9, target, origin;
    vector<iPair> adj[9];

    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);

    // for (auto &i : adj)
    // {
    //     for (auto &j : i)
    //     {;
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    cout << "input origin: ";
    cin >> origin;

    cout << "input target: ";
    cin >> target;

    shortestPath(adj, V, origin, target);

    return 0;
}