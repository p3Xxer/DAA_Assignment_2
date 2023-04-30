// SULTAN KO SIRF SULTAN HARA SAKTA HAIN !!
/**
 * @file Q1.cpp
 * @brief Ford Fulkerson Algorithm
 * @details
 */
#include <algorithm>
#include <fstream>
#include <climits>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>

using namespace std;
#define ll long long int
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
const ll inf = 1e18;
const ll mod = 1e9 + 7;

/**
 * @brief Edge structure
 * @details
 * v: source
 * u: destination
 * capacity: capacity of the edge
 * flow: flow of the edge
 */
struct Edge
{
    int v, u, capacity, flow;
};

/**
 * @brief Add edge to the graph
 * @details
 * @param v source
 * @param u destination
 * @param capacity capacity of the edge
 * @param graph graph
 * @return void
 */
void add_edge(int v, int u, int capacity, vector<vector<Edge>> &graph)
{
    Edge e1 = {v, u, capacity, 0};
    Edge e2 = {u, v, 0, 0};
    graph[v].pb(e1);
    graph[u].pb(e2);
}

/**
 * @brief BFS
 * @details
 * @param graph graph
 * @param parent parent
 * @param s source
 * @param t destination
 * @return bool
 */
bool bfs(vector<vector<Edge>> &graph, vector<int> &parent, int s, int t)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        visited[u] = true;
        for (auto &e : graph[u])
        {
            int v = e.u;
            if (!visited[v] && e.capacity > e.flow)
            {
                visited[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return visited[t];
}

/**
 * @brief Augment
 * @details
 * @param graph graph
 * @param parent parent
 * @param s source
 * @param t destination
 * @return int
 * @note
 * 1. Find the minimum flow in the path
 * 2. Update the flow in the path
 * 3. Return the minimum flow
 * 4. Update the residual graph
 * 5. Repeat until there is no path from s to t
 * 6. The max flow is the sum of all the flows in the path
 * 7. The min cut is the set of all the vertices reachable from s in the residual graph
 */
int augment(vector<vector<Edge>> &graph, vector<int> &parent, int s, int t)
{
    int n = graph.size();
    int min_flow = INT_MAX;
    for (int v = t; v != s; v = parent[v])
    {
        int u = parent[v];
        for (auto &e : graph[u])
        {
            if (e.u == v)
            {
                min_flow = min(min_flow, e.capacity - e.flow);
                break;
            }
        }
    }
    for (int v = t; v != s; v = parent[v])
    {
        int u = parent[v];
        for (auto &e : graph[u])
        {
            if (e.u == v)
            {
                e.flow += min_flow;
                break;
            }
        }
        for (auto &e : graph[v])
        {
            if (e.u == u)
            {
                e.flow -= min_flow;
                break;
            }
        }
    }
    return min_flow;
}

/**
 * @brief Ford Fulkerson
 * @details
 * @param graph graph
 * @param s source
 * @param t destination
 * @return int
 * @note
 * 1. Find the path from s to t using BFS
 * 2. Augment the path
 * 3. Repeat until there is no path from s to t
 * 4. The max flow is the sum of all the flows in the path
 * 5. The min cut is the set of all the vertices reachable from s in the residual graph
 * @note
 * 1. Time complexity: O(E * max_flow)
 * 2. Space complexity: O(V + E)
 */
int ford_fulkerson(vector<vector<Edge>> &graph, int s, int t)
{
    int n = graph.size();
    vector<int> parent(n);
    int max_flow = 0;
    while (bfs(graph, parent, s, t))
    {
        int flow = augment(graph, parent, s, t);
        max_flow += flow;
    }
    return max_flow;
}

/**
 * @brief Print graph
 * @details
 * @param graph graph
 * @return void
 */
void print_graph(vector<vector<Edge>> &graph)
{
    int n = graph.size();
    for (int u = 0; u < n - 1; u++)
    {
        cout << u << " : ";
        for (auto &e : graph[u])
        {
            if (e.flow >= 0)
            {
                cout << e.u << " " << e.flow << "/" << e.capacity << " ";
            }
        }
        cout << endl;
    }
}

/**
 * @brief DFS
 * @details
 * @param graph graph
 * @param visited visited
 * @param s source
 * @return void
 */
void dfs(vector<vector<Edge>> &graph, vector<bool> &visited, int s)
{
    visited[s] = true;
    for (auto &e : graph[s])
    {
        if (!visited[e.u] && e.capacity > e.flow)
        {
            dfs(graph, visited, e.u);
        }
    }
}

/**
 * @brief Print cut
 * @details
 * @param graph graph
 * @param s source
 * @param t destination
 * @return void
 */
void print_cut(vector<vector<Edge>> &graph, int s, int t)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    dfs(graph, visited, s);
    cout << "The min s-t cut is: " << endl;
    for (int u = 0; u < n; u++)
    {
        if (visited[u])
        {
            for (auto &e : graph[u])
            {
                if (!visited[e.u])
                {
                    cout << u << "->" << e.u << endl;
                }
            }
        }
    }
}

/**
 * @brief Main function
 * @details
 * @return int
 */
int main()
{
    freopen("testcase1.txt", "r", stdin);
    freopen("output1.txt", "w+", stdout);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        add_edge(u, v, c, graph);
    }
    int max_flow = ford_fulkerson(graph, s, t);
    cout << "Maximum flow: " << max_flow << endl;
    cout << "The min s-t cut is: " << max_flow << endl;
    print_graph(graph);
    print_cut(graph, s, t);
    vector<bool> visited(n, false);
    dfs(graph, visited, s);
    cout << "The set of vertices that are reachable from s in the residual graph: ";
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "The set of vertices that are not reachable from s in the residual graph: ";
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
