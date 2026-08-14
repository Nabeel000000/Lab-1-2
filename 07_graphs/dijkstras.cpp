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

void Dijkstras(int x)
{
    dis[x] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    while (!pq.empty())
    {
        int v, d;
        tie(d, v) = pq.top();
        pq.pop();
        if (pro[v])
            continue;
        pro[v] = true;
        out(v);
        cout << endl;
        for (auto e : adj[v])
        {
            int u = e.F, w = e.S;
            if (dis[u] > dis[v] + w)
            {
                dis[u] = dis[v] + w;
                pq.push({-dis[u], u});
            }
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    adj.resize(6);
    pro.resize(6, 0);
    dis.resize(6, 0);
    adj[3].push_back({4, 6});
    adj[4].push_back({3, 6});
    adj[2].push_back({1, 5});
    adj[1].push_back({2, 5});
    adj[1].push_back({4, 9});
    adj[4].push_back({1, 9});
    adj[3].push_back({2, 2});
    adj[2].push_back({3, 2});
    adj[1].push_back({5, 1});
    adj[5].push_back({1, 1});
    adj[5].push_back({4, 2});
    adj[4].push_back({5, 2});
    Dijkstras(1);
    for (int i = 1; i <= 5; i++)
    {
        cout << i << ':' << dis[i] << '\n';
    }
    return 0;
}
