// perfect nth root

#include <stdio.h>
#define ll long long

ll power(ll m, int n, ll y)
{
    ll res = 1;
    for (int i = 0; i < n; i++)
    {

        if (res > y / m)
        {
            return y + 1;
        }
        res *= m;
    }
    return res;
}

ll nth_root(ll y, int n)
{
    ll l = 1;
    ll h = y;

    while (l <= h)
    {
        ll m = l + (h - l) / 2;
        ll val = power(m, n, y);

        if (val == y)
        {
            return m;
        }
        else if (val < y)
        {
            l = m + 1;
        }
        else
        {
            h = m - 1;
        }
    }

    return -1;
}

int main()
{
    ll y, n;
    printf("Enter number:");
    scanf("%lld", &y);
    printf("Enter the value of n(nth-root):");
    scanf("%lld", &n);

    ll res = nth_root(y, n);
    if (res != -1)
    {
        printf("The %d-th root of %lld is %lld\n", n, y, res);
    }
    else
    {
        printf("%lld does not have a perfect %d-th root\n", y, n);
    }

    return 0;
}
