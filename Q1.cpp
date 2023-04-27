//SULTAN KO SIRF SULTAN HARA SAKTA HAIN !!
#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
const ll inf=1e18;
const ll mod=1e9+7;

struct Edge {
    int v, u, capacity, flow;
};

void add_edge(int v, int u, int capacity, vector<vector<Edge>>& graph) {
    Edge e1 = {v, u, capacity, 0};
    Edge e2 = {u, v, 0, 0};
    graph[v].pb(e1);
    graph[u].pb(e2);
}

bool bfs(vector<vector<Edge>>& graph, vector<int>& parent, int s, int t) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        visited[u] = true;
        for (auto& e : graph[u]) {
            int v = e.u;
            if (!visited[v] && e.capacity > e.flow) {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return visited[t];
}

int augment(vector<vector<Edge>>& graph, vector<int>& parent, int s, int t) {
    int n = graph.size();
    int min_flow = INT_MAX;
    for (int v = t; v != s; v = parent[v]) {
        int u = parent[v];
        for (auto& e : graph[u]) {
            if (e.u == v) {
                min_flow = min(min_flow, e.capacity - e.flow);
                break;
            }
        }
    }
    for (int v = t; v != s; v = parent[v]) {
        int u = parent[v];
        for (auto& e : graph[u]) {
            if (e.u == v) {
                e.flow += min_flow;
                break;
            }
        }
        for (auto& e : graph[v]) {
            if (e.u == u) {
                e.flow -= min_flow;
                break;
            }
        }
    }
    return min_flow;
}

int ford_fulkerson(vector<vector<Edge>>& graph, int s, int t) {
    int n = graph.size();
    vector<int> parent(n);
    int max_flow = 0;
    while (bfs(graph, parent, s, t)) {
        int flow = augment(graph, parent, s, t);
        max_flow += flow;
    }
    return max_flow;
}

int main(){
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        add_edge(u, v, c, graph);
    }
    int max_flow = ford_fulkerson(graph, s, t);
    cout << "Maximum flow: " << max_flow << endl;
    return 0;   
}

