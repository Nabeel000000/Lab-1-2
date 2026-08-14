#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define int ll
#define INF 100000000000000010
#define M (ll)(1e9 + 7)
using namespace std;
#define sort(arr) sort(arr.begin(), arr.end())
#define be(arr) arr.begin(), arr.end()
#define F first
#define S second
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define pb(v) push_back(v)
#define pf(v) push_front(v)
#define FOR(arr)           \
    for (auto ai : arr)    \
        cout << ai << ' '; \
    cout << '\n';
#define OK cout << "OK" << endl
#define out(x) cout << #x << '=' << x << ' '

/*
****think harder
*/

/*problem statements
 */

/*Obs
 */

/*steps
 */

const int MAXN = 100005;
int parent_node[MAXN];
int sz[MAXN];
 
int n, m;                      
vector<vector<int>> edges;      
vector<vector<int>> mst_edges;  
int mst_cost = 0;               

void make_set(int v)
{
    parent_node[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (v == parent_node[v])
        return v;
    return parent_node[v] = find_set(parent_node[v]);
}

bool union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent_node[b] = a;
        sz[a] += sz[b];
        return true;
    }
    return false;
}


void kruskal()
{
    for (int i = 1; i <= n; i++)
        make_set(i);
    
    sort(edges.begin(), edges.end());

    for (int i = 0; i < edges.size(); i++)
    {
        int weight = edges[i][0];
        int u = edges[i][1];
        int v = edges[i][2];

        if (union_sets(u, v))
        {
            mst_cost += weight;
            mst_edges.push_back(edges[i]);
        }
    }
}


int32_t main()
{
   
    n = 4;
    m = 5;

   
    edges = {
        {10, 1, 2},
        {15, 2, 3},
        {5, 1, 3},
        {2, 4, 2},
        {40, 4, 3}};

    
    kruskal();
    cout << "Minimum Spanning Tree Cost: " << mst_cost << "\n";
    cout << "Edges in the MST:\n";
    for (int i = 0; i < mst_edges.size(); i++)
    {
        cout << mst_edges[i][1] << " - " << mst_edges[i][2]
             << " (Weight: " << mst_edges[i][0] << ")\n";
    }

    return 0;
}
