#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define INF 1000000010
#define M (ll)(1e9 + 7)
using namespace std;
#define sort(arr) sort(arr.begin(), arr.end())
#define BE(arr) arr.begin(), arr.end()
#define F first
#define S second
#define pb(val) push_back(val)
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

int toNum(string &num)
{
    reverse(BE(num));
    int n = num.size(), ans = 0, mul = 1;
    for (int i = 0; i < n; i++)
    {
        ans += (num[i] - '0') * mul;
        mul *= 10;
    }
    return ans;
}
int eval(string &s)
{
    char lope = '+';
    int ans = 0, n = s.size(), cval = 0, lval = 0;
    for (int i = 0; i < n; i++)
    {
        string num = "";
        while (i < n && s[i] >= '0' && s[i] <= '9')
            num.pb(s[i++]);

        cval = toNum(num);

        if (lope == '+')
        {
            ans += lval;
            lval = cval;
        }
        else if (lope == '-')
        {
            ans += lval;
            lval = -cval;
        }
        else if (lope == '*')
        {
            lval *= cval;
        }
        else if (lope == '/')
        {
            lval /= cval;
        }
        if (i < n && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'))
            lope = s[i];
    }
    return ans + lval;
}

vector<int> endb;
void pre(string &s)
{
    int n = s.size();
    endb.assign(n, -1);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(i);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            int top = st.top();
            st.pop();
            endb[top] = i;
            endb[i] = top;
        }
    }
}
int find(string &s, int l, int r)
{
    string orr = "";
    for (int i = l; i < r;)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            int val = find(s, i + 1, endb[i]);
            string trr = to_string(val);
            for (auto ti : trr)
                orr.pb(ti);
            i = endb[i] + 1;
        }
        else
        {
            orr.pb(s[i++]);
        }
    }
    return eval(orr);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    pre(s);
    cout << find(s, 0, n);
    // space and time complexity O(n);
    return 0;
}
